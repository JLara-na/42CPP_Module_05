/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:19:45 by jlara-na          #+#    #+#             */
/*   Updated: 2025/03/12 21:33:48 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		const int			_grade_to_sign;
		const int			_grade_to_execute;
		bool				_signed;
	
	public:
		Form();
		Form(const Form&other);
		Form(std::string name, int grade_to_sign, int grade_to_execute);
		~Form();
		Form&		operator=(const Form& other);
		std::string	getName() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		bool		getSigned() const;
		void		beSigned(Bureaucrat &signatory);

		class GradeTooHighException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream &out, Form const &other);