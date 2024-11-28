#include "Game.hpp"
#include <Engineer.hpp>
#include <Laborer.hpp>
#include <Marketer.hpp>
#include <WarehouseWorker.hpp>
#include <iostream>

Game::Game() : company(10000.0)
{ // Initial account balance
    // Add one employee of each type to the company
    company.hire(std::make_unique< Engineer >("Alice", "Mechanical"));
    company.hire(std::make_unique< WarehouseWorker >("Bob", true));
    company.hire(std::make_unique< Marketer >("Charlie", 1500));
    company.hire(std::make_unique< Laborer >("Dave", 42.5));
}

void Game::start()
{
    std::cout << "Welcome to the economic simulation game!\n"
              << "Your company starts with:\n"
              << "1 Engineer, 1 Warehouse Worker, 1 Marketer, 1 Laborer.\n"
              << "You have $10,000 in your account.\n"
              << "Commands:\n"
              << "lp - List all employees (names and salaries)\n"
              << "zinz - Hire an Engineer\n"
              << "zmag - Hire a Warehouse Worker\n"
              << "zmkt - Hire a Marketer\n"
              << "zrob - Hire a Laborer\n"
              << "kred - Take a loan (enter amount and duration)\n"
              << "kt - End the turn and show company status\n";

    bool running = true;

    while (running)
    {
        std::cout << "Enter command: ";
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "lp")
        {
            company.listEmployees();
        }
        else if (cmd == "zinz")
        {
            std::string name, dept;
            std::cout << "Enter name and department for the Engineer: ";
            std::cin >> name >> dept;
            company.hire(std::make_unique< Engineer >(name, dept));
            std::cout << "Engineer hired successfully!\n";
        }
        else if (cmd == "zmag")
        {
            std::string name;
            bool        hasForklift;
            std::cout << "Enter name and forklift ability (1 for yes, 0 for no): ";
            std::cin >> name >> hasForklift;
            company.hire(std::make_unique< WarehouseWorker >(name, hasForklift));
            std::cout << "Warehouse Worker hired successfully!\n";
        }
        else if (cmd == "zmkt")
        {
            std::string name;
            int         followers;
            std::cout << "Enter name and number of followers for the Marketer: ";
            std::cin >> name >> followers;
            company.hire(std::make_unique< Marketer >(name, followers));
            std::cout << "Marketer hired successfully!\n";
        }
        else if (cmd == "zrob")
        {
            std::string name;
            double      shoeSize;
            std::cout << "Enter name and shoe size for the Laborer: ";
            std::cin >> name >> shoeSize;
            company.hire(std::make_unique< Laborer >(name, shoeSize));
            std::cout << "Laborer hired successfully!\n";
        }
        else if (cmd == "kred")
        {
            double amount;
            int    term;
            std::cout << "Enter loan amount and duration (in months): ";
            std::cin >> amount >> term;
            company.takeLoan(amount, term);
            std::cout << "Loan of $" << amount << " taken for " << term << " months.\n";
        }
        else if (cmd == "kt")
        {
            company.endMonth();
            if (company.getBalance() < 0)
            {
                std::cout << "Your company has gone bankrupt. Game over.\n";
                running = false;
            }
        }
        else
        {
            std::cout << "Invalid command. Try again.\n";
        }
    }
}
