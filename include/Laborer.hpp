#ifndef LABORER_HPP
#define LABORER_HPP

#include "Employee.hpp"
#include <string>

class Laborer : public Employee {
public:
    Laborer(const std::string& name, int salary, double shoeSize);
    void displayInfo() const override;
    int calculateImpact() const override;
    int getSalary() const override;

private:
    double shoeSize;
};

#endif 
