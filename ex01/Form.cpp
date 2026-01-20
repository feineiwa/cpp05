/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:10:23 by frahenin          #+#    #+#             */
/*   Updated: 2025/09/15 13:21:00 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name(), sign(false), gradeToSign(150), gradeToExecute(150) {}

Form::~Form() {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
: name(name), sign(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other)
: name(other.name), sign(other.sign), gradeToSign(other.gradeToSign),
	gradeToExecute(other.gradeToExecute) {}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->sign = other.sign;
	}
	return (*this);
}

const std::string& Form::getName() const
{
	return (this->name);
}

bool Form::getSign() const
{
	return (sign);
}

int Form::getGradeToSign() const
{
	return (gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (gradeToExecute);
}

void Form::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();
	this->sign = true;
}

std::ostream& operator<<(std::ostream& o, Form const& i)
{
	o << i.getName() << ", sign " << i.getSign() << ", grade to sign " << i.getGradeToSign()
	<< ", grade to execute " << i.getGradeToExecute() << ".";
	return (o);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return("Form's grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return("Form's grade is too low");
}