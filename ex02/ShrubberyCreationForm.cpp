/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:01:33 by frahenin          #+#    #+#             */
/*   Updated: 2025/09/16 10:52:32 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("Default target") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
	: AForm(other), target(other.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const
{
	std::string outFile = this->target + "_shrubberry";
	std::ofstream ofs(outFile.c_str());

	if (ofs)
	{
		ofs << "      ccee88oo\n"
			<< "C8O8O8Q8PoOb o8oo\n"
			<< "dOB69QO8PdUOpugoO9bD\n"
			<< "CgggbU8OU qOp qOdoUOdcb\n"
			<< "   6OuU  /p u gcoUodpP\n"
			<< "   \\\\//  /douUP\n"
			<< "        \\\\////" << std::endl
			<< "       |||/\\" << std::endl
			<< "       |||\\/\n"
			<< "       |||||\n"
			<< "  .....//||||\\....";
		ofs.close();
	}
	else
		throw ShrubberyCreationForm::FileNotOpen();
}

const char *ShrubberyCreationForm::FileNotOpen::what() const throw()
{
	return ("Cannot open the file");
}
