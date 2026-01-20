/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:46:38 by frahenin          #+#    #+#             */
/*   Updated: 2026/01/19 13:57:14 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_H__
# define __BUREAUCRAT_H__

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;

		Bureaucrat();
	public:
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& other);
		
		const std::string&	getName(void) const;
		int	getGrade(void) const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char * what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				virtual const char * what() const throw();
		};
		
		void	incrementGrade();
		void	decrementGrade();

		void signForm(AForm& form);

		void executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const& i);

#endif