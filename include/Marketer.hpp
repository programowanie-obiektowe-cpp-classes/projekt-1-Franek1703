#ifndef MARKETER_HPP
#define MARKETER_HPP

#include "Employee.hpp"
#include <string>

class Marketer : public Employee {
public:
    Marketer(const std::string& name, int salary, int followers);
    void displayInfo() const override;
    int calculateImpact() const override;
    int getSalary() const override;

private:
    int socialMediaFollowers;
};

#endif
