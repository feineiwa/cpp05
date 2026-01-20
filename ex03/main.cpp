/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frahenin <frahenin@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:45:38 by frahenin          #+#    #+#             */
/*   Updated: 2025/10/20 12:31:17 by frahenin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    // Bureaucrat boss("Boss", 10);
    // Bureaucrat worker("Worker", 137);
    
    // ShrubberyCreationForm shrub("home");
    // RobotomyRequestForm robo("Bender");
    // PresidentialPardonForm pardon("Pardon");

    // std::cout << shrub << std::endl;
    // std::cout << robo << std::endl;
    // std::cout << pardon << std::endl;
    // std::cout << "-----------------------" << std::endl;
    
    // worker.executeForm(shrub);
    // std::cout << "-----------------------" << std::endl;
    
    // boss.signForm(shrub);
    // boss.signForm(robo);
    // boss.signForm(pardon);

    // std::cout << "-----------------------" << std::endl;

    // worker.executeForm(robo);
    // std::cout << "-----------------------" << std::endl;


    // boss.executeForm(shrub);
    // boss.executeForm(robo);
    // boss.executeForm(pardon);
    // std::cout << "-----------------------" << std::endl;
    
    // boss.incrementGrade();
    // boss.incrementGrade();
    // boss.incrementGrade();
    // boss.incrementGrade();
    // boss.incrementGrade();
    // boss.executeForm(pardon);
    
    {
        Bureaucrat boss("Boss", 10);
        Intern someRandomIntern;
        AForm* rrf;

        rrf = someRandomIntern.makeForm("robotomy request", "bender");
        if (rrf)
        {
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf;
        }

        AForm *ppf;

        ppf = someRandomIntern.makeForm("presidential pardon", "pardon");
        if (ppf)
        {
            boss.executeForm(*ppf);
            delete ppf;
        }

        AForm *scf;

        scf = someRandomIntern.makeForm("shrubbery creation", "home");
        if (scf)
        {
            boss.signForm(*scf);
            boss.executeForm(*scf);
            delete scf;
        }

        AForm *unkn;
        
        unkn = someRandomIntern.makeForm("sadfjasdfhaljsdhfa", "unknown");
        if (unkn) delete unkn;
    }
    return 0;
}