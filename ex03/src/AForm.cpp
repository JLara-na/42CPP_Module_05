/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlara-na <jlara-na@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:19:43 by jlara-na          #+#    #+#             */
/*   Updated: 2025/04/15 10:24:10 by jlara-na         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

AForm::AForm() : _name("Nameless AForm"), _grade_to_sign(150), _grade_to_execute(150), _signed(false){
	// std::cout << "AForm Constructor called!" << std::endl;
}

AForm::AForm(const AForm&other) : _name(other._name), _grade_to_sign(other._grade_to_execute), _grade_to_execute(other._grade_to_execute), _signed(other._signed){
	// std::cout << "AForm Copy constructor called!" << std::endl;
	*this = other;
    if (this->_grade_to_sign < 1 || this->_grade_to_execute < 1)
		throw (AForm::GradeTooHighException());
	if (this->_grade_to_sign > 150 || this->_grade_to_execute > 150)
		throw (AForm::GradeTooLowException());
}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_execute) : _name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute), _signed(false){
	// std::cout << "AForm Constructor called!" << std::endl;
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw (AForm::GradeTooHighException());
	if (grade_to_sign > 150 || grade_to_execute > 150)
		throw (AForm::GradeTooLowException());
}

AForm::~AForm(){
	// std::cout << "AForm Destructor called!" << std::endl;
}

std::string	AForm::getName() const{
	return(this->_name);
}

int			AForm::getGradeToSign() const{
	return(this->_grade_to_sign);
}

int			AForm::getGradeToExecute() const{
	return(this->_grade_to_execute);
}

bool		AForm::getSigned() const{
	return(this->_signed);
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other){
		this->_signed = other.getSigned();
	}
	return (*this);
}

void		AForm::beSigned(Bureaucrat& signatory){
    if (signatory.getGrade() > _grade_to_sign)
		throw (AForm::GradeTooLowException());
    _signed = true;
}

std::ostream& operator<<(std::ostream &out, AForm const &other){
    out << "AForm: " << other.getName() << " , signed status (" << other.getSigned()
    << "), Grade to sign (>= " << other.getGradeToSign() << ") , Grade to execute (>="
    << other.getGradeToExecute() << ")";
    return (out);
}

const char* AForm::GradeTooHighException::what() const throw(){
    return ("AForm: GradeTooHighException");
}

const char* AForm::GradeTooLowException::what() const throw(){
    return ("AForm: GradeTooLowException");
}