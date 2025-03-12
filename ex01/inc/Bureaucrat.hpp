/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:24:52 by jlara-na          #+#    #+#             */
/*   Updated: 2025/03/12 21:31:51 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include "Form.hpp"

class Bureaucrat{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat&	operator=(const Bureaucrat& other);
		std::string	getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();
		void		signForm(Form& form);
		class GradeTooHighException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream &out, Bureaucrat const &other);