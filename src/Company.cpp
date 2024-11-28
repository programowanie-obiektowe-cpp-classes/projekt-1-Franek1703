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