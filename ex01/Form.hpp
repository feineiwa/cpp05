/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:11:02 by frahenin          #+#    #+#             */
/*   Updated: 2025/08/21 12:27:34 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_H__
# define __FORM_H__

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool	sign;
		const	int gradeToSign;
		const	int gradeToExecute;
		
		Form();
	public:
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		~Form();
		Form& operator=(const Form& other);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char * what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				virtual const char * what() const throw();
		};

		const std::string& getName() const;
		bool getSign() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(Bureaucrat const& b);
		
};

std::ostream& operator<<(std::ostream& o, Form const& i);

#endif