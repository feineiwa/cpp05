/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:11:02 by frahenin          #+#    #+#             */
/*   Updated: 2025/10/14 15:35:02 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AFORM_H__
#define __AFORM_H__

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool sign;
	const int gradeToSign;
	const int gradeToExecute;

	virtual void executeAction() const = 0;
	AForm();
	
public:
	AForm(const std::string &name, int gradeToSign, int gradeToExecute);
	AForm(const AForm &other);
	virtual ~AForm();
	AForm &operator=(const AForm &other);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	const std::string &getName() const;
	bool getSign() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(Bureaucrat const &b);

	void execute(Bureaucrat const &executor) const;

	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, AForm const &i);

#endif