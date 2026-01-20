/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:45:38 by frahenin          #+#    #+#             */
/*   Updated: 2025/10/14 11:11:57 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat faneva("faneva", 150);
		std::cout << faneva << std::endl;
		faneva.decrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat foo("foo", 1);
		std::cout << foo << std::endl;
		foo.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat bar1("bar1", 230);
		std::cout << bar1 << std::endl;
		bar1.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		Bureaucrat bar("bar", -56);
		std::cout << bar << std::endl;
		bar.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}