#ifndef COMPANY_HPP
#define COMPANY_HPP

#include <vector>
#include <memory>
#include "Employee.hpp"

class Company {
    double accountBalance;
    std::vector<std::unique_ptr<Employee>> employees;

public:
    Company(double initialBalance);

    void hire(std::unique_ptr<Employee> employee);
    void listEmployees() const;
};

#endif 
