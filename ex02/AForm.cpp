/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:10:23 by frahenin          #+#    #+#             */
/*   Updated: 2025/10/17 12:02:09 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name(), sign(false), gradeToSign(150), gradeToExecute(150) {}

AForm::~AForm() {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
	: name(name), sign(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other)
	: name(other.name), sign(other.sign), gradeToSign(other.gradeToSign),
	  gradeToExecute(other.gradeToExecute) {}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->sign = other.sign;
	}
	return (*this);
}

const std::string &AForm::getName() const
{
	return (this->name);
}

bool AForm::getSign() const
{
	return (sign);
}

int AForm::getGradeToSign() const
{
	return (gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (gradeToExecute);
}

void AForm::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException();
	this->sign = true;
}

std::ostream &operator<<(std::ostream &o, AForm const &i)
{
	o << i.getName() << ", sign " << i.getSign() << ", grade to sign " << i.getGradeToSign()
	  << ", grade to execute " << i.getGradeToExecute() << ".";
	return (o);
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!sign)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > gradeToExecute)
		throw AForm::GradeTooLowException();
	executeAction();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return("Form's grade is too hight");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return("Form's grade is too low");
}

const char *AForm::FormNotSignedException::what() const throw ()
{
	return ("Form is not signed");
}