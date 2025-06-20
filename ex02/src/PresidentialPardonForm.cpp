/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:19:58 by jlara-na          #+#    #+#             */
/*   Updated: 2025/06/20 13:46:34 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Nameless"){
	// std::cout << "PresidentialPardonForm Constructor called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm&other) : AForm("PresidentialPardonForm", 25, 5), _target(other._target){
	// std::cout << "PresidentialPardonForm Copy constructor called!" << std::endl;
	*this = other;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target){
	// std::cout << "PresidentialPardonForm Constructor called!" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	// std::cout << "PresidentialPardonForm Destructor called!" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	// std::cout << "PresidentialPardonForm = operator called!" << std::endl;
	if (this != &other){
		*this = other;
	}
	return (*this);
}

void		PresidentialPardonForm::execute(Bureaucrat const &executor) const{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}