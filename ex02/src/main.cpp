/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:24:50 by jlara-na          #+#    #+#             */
/*   Updated: 2025/06/20 13:45:43 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int main(void)
{
	std::cout << "Creating Bureaucrats" << std::endl;
	Bureaucrat president("President", 1);
	Bureaucrat robot("Robot", 45);
	Bureaucrat treemaker("Treemaker", 137);

	std::cout << std::endl << "Creating Forms" << std::endl;
	PresidentialPardonForm	presi("t1");
	RobotomyRequestForm		robotomy("t2");
	ShrubberyCreationForm	forest("t3");

	/*This should work*/
	try{
		president.executeForm(presi);
		std::cout << std::endl;
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	try{
		robot.executeForm(robotomy);
		std::cout << std::endl;
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	try{
		treemaker.executeForm(forest);
		std::cout << std::endl;
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	/*This should not work*/
	
	std::cout << "Creating bad_Bureaucrats" << std::endl;
	Bureaucrat bad_president("bad_President", 150);
	Bureaucrat bad_robot("bad_Robot", 150);
	Bureaucrat bad_treemaker("bad_Treemaker", 150);

	std::cout << std::endl << "Creating bad_Forms" << std::endl;
	PresidentialPardonForm	bad_presi("t1");
	RobotomyRequestForm		bad_robotomy("t2");
	ShrubberyCreationForm	bad_forest("t3");

	/*This should work*/
	try{
		bad_president.executeForm(bad_presi);
		std::cout << std::endl;
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	try{
		bad_robot.executeForm(bad_robotomy);
		std::cout << std::endl;
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	try{
		bad_treemaker.executeForm(bad_forest);
		std::cout << std::endl;
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}
}