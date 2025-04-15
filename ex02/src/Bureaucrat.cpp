/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:24:47 by jlara-na          #+#    #+#             */
/*   Updated: 2025/03/12 21:10:59 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Nameless") , _grade(150){
	// std::cout << "Constructor called!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat&other){
	// std::cout << "Copy constructor called!" << std::endl;
	*this = other;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){
	// std::cout << "Constructor called!" << std::endl;
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat(){
	// std::cout << "Destructor called!" << std::endl;
}

std::string	Bureaucrat::getName() const{
	return(this->_name);
}

int			Bureaucrat::getGrade() const{
	return(this->_grade);
}

void		Bureaucrat::incrementGrade(){
    if (this->getGrade() <= 1)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade--;
}

void		Bureaucrat::decrementGrade(){
	if (this->getGrade() >= 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade++;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other){
		this->_grade = other.getGrade();
	}
	return (*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return ("Bureaucrat: TooHighException");
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return ("Bureaucrat: TooLowException");
}

std::ostream& operator<<(std::ostream &out, Bureaucrat const &other){
    out << other.getName() << ", bureaucrat grade " << other.getGrade();
    return (out);
}

void		Bureaucrat::signForm(Form& form){
	try {
		if (_grade < 1)
			throw (Bureaucrat::GradeTooHighException());
		if (_grade > 150)
			throw (Bureaucrat::GradeTooLowException());
		form.beSigned(*this);
		std::cout << "Bureaucrat " << _name << " has signed the form: " << form.getName() << std::endl;
	}
	catch (const std::exception& exception){
		std::cout << "Bureaucrat " << _name << " couldnt sign the form: " << form.getName()
		<< ", grade required: " << form.getGradeToSign() << ", actual grade: " << _grade << std::endl;
	}
}
