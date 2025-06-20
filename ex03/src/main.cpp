/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:24:50 by jlara-na          #+#    #+#             */
/*   Updated: 2025/06/20 16:34:53 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Intern.hpp"


int main(void)
{
	/*This should work*/
	Intern	intern;
	Bureaucrat	bureaucrat("The president", 1);
	AForm	*presidentialP = NULL;
	AForm	*robotomyR = NULL;
	AForm	*shrubberyC = NULL;
	AForm	*invalidform = NULL;

	try{
		presidentialP = intern.makeForm("presidential", "presidential_target");
		robotomyR = intern.makeForm("robotomy", "robotomy_target");
		shrubberyC = intern.makeForm("shrubbery", "shrubbery_target");
		invalidform = intern.makeForm("INVALID", "INVALID_TARGET");
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	try{
		if (presidentialP)
			bureaucrat.executeForm(*presidentialP);
		if (robotomyR)
			bureaucrat.executeForm(*robotomyR);
		if (shrubberyC)
			bureaucrat.executeForm(*shrubberyC);
		if (invalidform)
			bureaucrat.executeForm(*invalidform);
		else
			std::cout << "Invalid form, does not exist" << std::endl;
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	delete presidentialP;
	delete robotomyR;
	delete shrubberyC;
	delete invalidform;
}