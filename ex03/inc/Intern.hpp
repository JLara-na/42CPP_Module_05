/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:02:27 by jlara-na          #+#    #+#             */
/*   Updated: 2025/06/20 15:30:56 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
# include <iostream>

class Intern
{
	public:
		Intern();
		Intern(const Intern& other);
		~Intern();
		Intern&		operator=(const Intern& other);
		
		AForm		*makeForm(std::string formName, std::string formTarget);
};
