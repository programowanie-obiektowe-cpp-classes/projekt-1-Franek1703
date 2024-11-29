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
    std::cout << "Total loan installments paid: $" << totalInstallments << "\n";
}

double Company::calculateRevenue() const {
     int marketers = 0, engineers = 0, laborers = 0, warehouseWorkers = 0;
    for (const auto& e : employees) {
        if (dynamic_cast<const Marketer*>(e.get())) marketers++;
        if (dynamic_cast<const Engineer*>(e.get())) engineers++;
        if (dynamic_cast<const Laborer*>(e.get())) laborers++;
        if (dynamic_cast<const WarehouseWorker*>(e.get())) warehouseWorkers++;
    }

    int theoreticalProduction = laborers * Laborer::CR;
    int maxCapacity = warehouseWorkers * WarehouseWorker::CMag;
    int demand = marketers * Marketer::CMkt;
    double productPrice = engineers * Engineer::CI;

    int actualProduction = std::min(theoreticalProduction, maxCapacity);
    int soldProducts = std::min(demand, actualProduction);

    return soldProducts * productPrice;
   
}

void Company::paySalaries() {
    double totalSalaries = 0.0;
    for (const auto& employee : employees) {
        totalSalaries += employee->getSalary();
    }
    accountBalance -= totalSalaries;
    std::cout << "Total salaries paid: $" << totalSalaries << "\n";
}

void Company::receiveIncome() {
    double revenue = calculateRevenue();
    accountBalance += revenue;
    std::cout << "Income received: $" << revenue << "\n";
}

void Company::endMonth() {
    std::cout << "Month Summary:\n";
    receiveIncome();
    paySalaries();
    payInstallments();


    std::cout << "Remaining Balance: $" << accountBalance << "\n";
    if (!loans.empty()) {
        std::cout << "Loans:\n";
        for (size_t i = 0; i < loans.size(); ++i) {
            std::cout << "  Loan " << i + 1 << ": Remaining Amount: $"
                      << loans[i].getRemainingAmount()
                      << ", Monthly Payment: $"
                      << loans[i].getMonthlyPayment()
                      << ", Remaining Installments: "
                      << loans[i].getRemainingInstallments() << "\n";
        }
    } else {
        std::cout << "No active loans.\n";
    }
}

double Company::getBalance() const {
    return accountBalance;
}
