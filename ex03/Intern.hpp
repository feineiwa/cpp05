/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 11:01:09 by frahenin          #+#    #+#             */
/*   Updated: 2025/10/20 11:19:43 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{

	public:
		Intern();
		Intern(const Intern &other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm *makeForm(const std::string &formName, const std::string &target);

		static AForm *createShrubbery(const std::string &target);
		static AForm *createRobotomy(const std::string &target);
		static AForm *createPresidential(const std::string &target);
};

#endif