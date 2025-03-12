/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:24:50 by jlara-na          #+#    #+#             */
/*   Updated: 2025/03/12 20:16:17 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main(void)
{
	std::cout << "\033[31mException type: too high\033[m" << std::endl;
	try {
		Bureaucrat bureaucrat_1("Jorge", 2);

		std::cout << bureaucrat_1 << std::endl;
		bureaucrat_1.incrementGrade();
		std::cout << bureaucrat_1 << std::endl;
		bureaucrat_1.incrementGrade();
		std::cout << "This should not be printed" << std::endl;
	}
	catch (std::exception &exception){
		std::cout << exception.what() << std::endl;
	}
	std::cout << "\033[31mException type: too low\033[m" << std::endl;
	try {
		Bureaucrat bureaucrat_2("Jorge", 149);

		std::cout << bureaucrat_2 << std::endl;
		bureaucrat_2.decrementGrade();
		std::cout << bureaucrat_2 << std::endl;
		bureaucrat_2.decrementGrade();
		std::cout << "This should not be printed" << std::endl;
	}
	catch (std::exception &exception){
		std::cout << exception.what() << std::endl;
	}
	std::cout << "\033[31mBad constructor arguments\033[m" << std::endl;
	try {
		std::cout << "\033[33mBureaucrat bureaucrat_3(\"Jorge\", 151);\033[m" << std::endl;
		Bureaucrat bureaucrat_3("Jorge", 151);
	}
	catch (std::exception &exception){
		std::cout << exception.what() << std::endl;
	}
	try {
		std::cout << "\033[33mBureaucrat bureaucrat_4(\"Jorge\", 0);\033[m" << std::endl;
		Bureaucrat bureaucrat_4("Jorge", 0);
	}
	catch (std::exception &exception){
		std::cout << exception.what() << std::endl;
	}
	std::cout << "\033[32mNormal behaviour\033[m" << std::endl;
	try {
		Bureaucrat bureaucrat_5("Jorge", 3);

		std::cout << bureaucrat_5 << std::endl;
		bureaucrat_5.incrementGrade();
		std::cout << bureaucrat_5 << std::endl;
		bureaucrat_5.incrementGrade();
		std::cout << bureaucrat_5 << std::endl;
		bureaucrat_5.decrementGrade();
		std::cout << bureaucrat_5 << std::endl;
	}
	catch (std::exception &exception){
		std::cout << exception.what() << std::endl;
	}
	return (0);
}