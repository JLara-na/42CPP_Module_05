/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:24:50 by jlara-na          #+#    #+#             */
/*   Updated: 2025/05/27 22:11:12 by jlara-na         ###   ########.fr       */
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
	Bureaucrat bur1("Presi",	1);
	Bureaucrat bur2("Robot",	45);
	Bureaucrat bur3("Forest",	137);

	std::cout << std::endl << "Creating Forms" << std::endl;
	PresidentialPardonForm	presi("may I beg your pardon");
	RobotomyRequestForm		robotomy("bip bop bup");
	ShrubberyCreationForm	forest("create trees");

	//* Presi will execute PresidentialPardonForm
	try
	{
		bur1.executeForm(presi);
		std::cout << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	//* Robot will execute RobotomyRequstForm
	try
	{
		bur2.executeForm(robotomy);
		std::cout << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	//* Forest will execute ShrubberyCreationForm
	try
	{
		bur3.executeForm(forest);
		std::cout << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}