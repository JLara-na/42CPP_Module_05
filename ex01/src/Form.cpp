/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:19:43 by jlara-na          #+#    #+#             */
/*   Updated: 2025/03/12 21:35:56 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

Form::Form() : _name("Nameless Form"), _grade_to_sign(150), _grade_to_execute(150), _signed(false){
	// std::cout << "Constructor called!" << std::endl;
}

Form::Form(const Form&other) : _name(other._name), _grade_to_sign(other._grade_to_execute), _grade_to_execute(other._grade_to_execute), _signed(other._signed){
	// std::cout << "Copy constructor called!" << std::endl;
	*this = other;
    if (this->_grade_to_sign < 1 || this->_grade_to_execute < 1)
		throw (Form::GradeTooHighException());
	if (this->_grade_to_sign > 150 || this->_grade_to_execute > 150)
		throw (Form::GradeTooLowException());
}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute) : _name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute), _signed(false){
	// std::cout << "Constructor called!" << std::endl;
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw (Form::GradeTooHighException());
	if (grade_to_sign > 150 || grade_to_execute > 150)
		throw (Form::GradeTooLowException());
}

Form::~Form(){
	// std::cout << "Destructor called!" << std::endl;
}

std::string	Form::getName() const{
	return(this->_name);
}

int			Form::getGradeToSign() const{
	return(this->_grade_to_sign);
}

int			Form::getGradeToExecute() const{
	return(this->_grade_to_execute);
}

bool		Form::getSigned() const{
	return(this->_signed);
}

Form& Form::operator=(const Form& other)
{
	if (this != &other){
		this->_signed = other.getSigned();
	}
	return (*this);
}

void		Form::beSigned(Bureaucrat& signatory){
    if (signatory.getGrade() > _grade_to_sign)
		throw (Form::GradeTooLowException());
    _signed = true;
}

std::ostream& operator<<(std::ostream &out, Form const &other){
    out << "Form: " << other.getName() << " , signed status (" << other.getSigned()
    << "), Grade to sign (>= " << other.getGradeToSign() << ") , Grade to execute (>="
    << other.getGradeToExecute() << ")";
    return (out);
}

const char* Form::GradeTooHighException::what() const throw(){
    return ("Form: GradeTooHighException");
}

const char* Form::GradeTooLowException::what() const throw(){
    return ("Form: GradeTooLowException");
}