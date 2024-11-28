#ifndef COMPANY_HPP
#define COMPANY_HPP

#include "Employee.hpp"
#include <memory>
#include <vector>
#include "Loan.hpp"

class Company
{
    double accountBalance;
    std::vector< std::unique_ptr< Employee > > employees;
    std::vector<Loan> loans;

public:
    Company(double initialBalance);

    void hire(std::unique_ptr< Employee > employee);
    void listEmployees() const;

    void takeLoan(double amount, int term);
    void payInstallments();

    double calculateRevenue() const;
    void   endMonth();
    double getBalance() const;

    ~Company() = default;
};

#endif
