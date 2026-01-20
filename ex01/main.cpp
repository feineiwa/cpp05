/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:45:38 by frahenin          #+#    #+#             */
/*   Updated: 2025/10/14 15:15:05 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Form f("F", 0, 151);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    try
    {
        Form f1("F1", 5, 250);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout << std::endl;
    try
    {
        Bureaucrat faneva("Faneva", 10);
        Bureaucrat fanilo("Fanilo", 150);

        Form foo("Foo", 150, 50);
        Form bar("bar", 1, 10);
        
        std::cout << faneva << std::endl;
        std::cout << fanilo << std::endl;
        std::cout << foo << std::endl;
        std::cout << bar << std::endl << std::endl;
        
        faneva.signForm(foo);
        faneva.signForm(bar);
        fanilo.signForm(foo);
        fanilo.signForm(bar);

    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }    
    return 0;
}