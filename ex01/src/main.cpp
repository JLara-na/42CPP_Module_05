/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:24:50 by jlara-na          #+#    #+#             */
/*   Updated: 2025/03/12 21:45:57 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main(void)
{
	std::cout << "\033[31mBad declaration arguments\033[m" << std::endl;
	try {
		Form		form_error("errorForm", 151, 151);
		
		std::cout << "this shoudnt be printed" << std::endl;
	}
	catch (std::exception &exception){
		std::cout << exception.what() << std::endl;
	}
	try {
		Form		form_error("errorForm", 0, 0);
		
		std::cout << "this shoudnt be printed" << std::endl;
	}
	catch (std::exception &exception){
		std::cout << exception.what() << std::endl;
	}
	std::cout << "\033[32mNormal behaviour (Form::beSigned()) lvl42 Bureaucrat\033[m" << std::endl;
	try {
		Bureaucrat	bureaucrat("Jorge", 42);
		Form		form_42("Rule 42", 42, 42);
		Form		form_41("Rule 41", 41, 41);

		std::cout << bureaucrat << std::endl;
		std::cout << form_42 << std::endl;
		form_42.beSigned(bureaucrat);
		std::cout << form_42 << std::endl;
		std::cout << form_41 << std::endl;
		form_41.beSigned(bureaucrat);
		std::cout << "this shoudnt be printed" << std::endl;
	}
	catch (std::exception &exception){
		std::cout << exception.what() << std::endl;
	}
	std::cout << "\033[32mNormal behaviour (Bureaucrat::signForm()) lvl42 Bureaucrat\033[m" << std::endl;
	try {
		Bureaucrat	bureaucrat("Jorge", 42);
		Form		form_1("Boring", 150, 150);
		Form		form_2("Exciting", 1, 1);

		std::cout << bureaucrat << std::endl;
		bureaucrat.signForm(form_1);
		bureaucrat.signForm(form_2);
	}
	catch (std::exception &exception){
		std::cout << exception.what() << std::endl;
	}
	return (0);
}