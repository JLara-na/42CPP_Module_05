/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:20:04 by jlara-na          #+#    #+#             */
/*   Updated: 2025/06/20 13:52:09 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Nameless"){
	// std::cout << "RobotomyRequestForm Constructor called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm&other) : AForm("RobotomyRequestForm", 72, 45), _target(other._target){
	// std::cout << "RobotomyRequestForm Copy constructor called!" << std::endl;
	*this = other;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target){
	// std::cout << "RobotomyRequestForm Constructor called!" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	// std::cout << "RobotomyRequestForm Destructor called!" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	// std::cout << "RobotomyRequestForm = operator called!" << std::endl;
	if (this != &other){
		*this = other;
	}
	return (*this);
}

void		RobotomyRequestForm::execute(Bureaucrat const &executor) const{
	struct timeval currentTime;
    long long ms;

    gettimeofday(&currentTime, NULL);
	ms = currentTime.tv_usec;
	std::cout << executor.getName() << ": " << "Makes some drilling noises!" << std::endl;
    if (ms % 2 == 0)
        std::cout << this->_target << " has been robotomized" << std::endl;
    else
        std::cout << "The robotomy failed." << std::endl;
}