#ifndef MARKETER_HPP
#define MARKETER_HPP

#include "Employee.hpp"
#include <string>

class Marketer : public Employee {
public:
    Marketer(const std::string& name, int followers);
    void displayInfo() const override;
    int calculateImpact() const override;

private:
    int socialMediaFollowers;
};

#endif
