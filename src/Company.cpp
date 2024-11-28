#include "Company.hpp"
#include "Engineer.hpp"
#include "WarehouseWorker.hpp"
#include "Marketer.hpp"
#include "Laborer.hpp"

Company::Company(double initialBalance) : accountBalance(initialBalance) {}

void Company::hire(std::unique_ptr<Employee> employee) {
    employees.push_back(std::move(employee));
}

void Company::listEmployees() const {
    for (const auto& e : employees) {
        e->displayInfo();
    }
}
void Company::takeLoan(double amount, int term) {
    loans.emplace_back(amount, term);
    accountBalance += amount;
}

void Company::payInstallments() {
    double totalInstallments = 0.0;
    for (auto it = loans.begin(); it != loans.end();) {
        totalInstallments += it->getMonthlyPayment();
        it->reduceInstallment();
        if (it->isPaidOff()) {
            it = loans.erase(it);
        } else {
            ++it;
        }
    }
    accountBalance -= totalInstallments;
}

double Company::calculateRevenue() const {
     int marketers = 0, engineers = 0, laborers = 0, warehouseWorkers = 0;
    for (const auto& e : employees) {
        if (dynamic_cast<const Marketer*>(e.get())) marketers++;
        if (dynamic_cast<const Engineer*>(e.get())) engineers++;
        if (dynamic_cast<const Laborer*>(e.get())) laborers++;
        if (dynamic_cast<const WarehouseWorker*>(e.get())) warehouseWorkers++;
    }

    int theoreticalProduction = laborers * 50; // CR = 50
    int maxCapacity = warehouseWorkers * 100; // CMag = 100
    int demand = marketers * 70; // CMkt = 70
    double productPrice = engineers * 200; // CI = 200

    int actualProduction = std::min(theoreticalProduction, maxCapacity);
    int soldProducts = std::min(demand, actualProduction);

    return soldProducts * productPrice;
   
}

void Company::endMonth() {
    double revenue = calculateRevenue();
    double salaryCost = 0.0;

    for (const auto& e : employees) {
        salaryCost += e->getSalary();
    }

    payInstallments();
    accountBalance += revenue - salaryCost;

    std::cout << "Month Summary:\n"
              << "Revenue: $" << revenue << "\n"
              << "Salaries: $" << salaryCost << "\n"
              << "Remaining Balance: $" << accountBalance << "\n";
}

double Company::getBalance() const {
    return accountBalance;
}
