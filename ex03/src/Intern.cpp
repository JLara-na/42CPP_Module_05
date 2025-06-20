/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:02:01 by jlara-na          #+#    #+#             */
/*   Updated: 2025/06/20 16:32:46 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"


Intern::Intern(){
	// std::cout << "Intern Constructor called!" << std::endl;
}
Intern::Intern(const Intern&other){
	// std::cout << "Intern Copy constructor called!" << std::endl;
	*this = other;
}

Intern::~Intern(){
	// std::cout << "Intern Destructor called!" << std::endl;
}

Intern& Intern::operator=(const Intern& other){
	if (this != &other){
		*this = other;
	}
	return (*this);
}

AForm		*Intern::makeForm(std::string formName, std::string formTarget){
	std::string	formNames[] = {"presidential", "robotomy", "shrubbery"};
	int cases = 3;
    for (std::string::iterator i = formName.begin(); i != formName.end(); i++)
		*i = std::tolower(*i);
	for (int i = 0; i < 3; i++){
		if (formName == formNames[i]){
			cases = i;
			break ;
		}
	}
	switch (cases){
		case 0:{
			std::cout << "Intern creates PresidentialPardonForm" << std::endl;
			return (new PresidentialPardonForm(formTarget));
		}
		case 1:{
			std::cout << "Intern creates RobotomyRequestForm" << std::endl;
			return (new RobotomyRequestForm(formTarget));
		}
		case 2:{
			std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
			return (new ShrubberyCreationForm(formTarget));
		}
		default: throw (std::runtime_error("Intern cant create: " + formName)); 
	}
}