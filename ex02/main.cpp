/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:45:38 by frahenin          #+#    #+#             */
/*   Updated: 2025/10/17 12:45:08 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    Bureaucrat boss("Boss", 10);
    Bureaucrat worker("Worker", 137);
    
    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robo("Bender");
    PresidentialPardonForm pardon("Pardon");

    std::cout << shrub << std::endl;
    std::cout << robo << std::endl;
    std::cout << pardon << std::endl;
    std::cout << "-----------------------" << std::endl;
    
    worker.executeForm(shrub);
    std::cout << "-----------------------" << std::endl;
    
    boss.signForm(shrub);
    boss.signForm(robo);
    boss.signForm(pardon);

    std::cout << "-----------------------" << std::endl;

    worker.executeForm(robo);
    std::cout << "-----------------------" << std::endl;


    boss.executeForm(shrub);
    boss.executeForm(robo);
    boss.executeForm(pardon);
    std::cout << "-----------------------" << std::endl;
    
    boss.incrementGrade();
    boss.incrementGrade();
    boss.incrementGrade();
    boss.incrementGrade();
    boss.incrementGrade();
    boss.executeForm(pardon);
    return 0;
}