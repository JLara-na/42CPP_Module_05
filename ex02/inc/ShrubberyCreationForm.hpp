/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:07:43 by jlara-na          #+#    #+#             */
/*   Updated: 2025/05/27 22:05:32 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AForm.hpp"
#include "Bureaucrat.hpp"
# include <fstream>
# include <sys/time.h>

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string	_target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm&other);
		ShrubberyCreationForm(const std::string target);
		~ShrubberyCreationForm();
	
		ShrubberyCreationForm&		operator=(const ShrubberyCreationForm& other);
		virtual void		execute(Bureaucrat const &executor) const;
};
