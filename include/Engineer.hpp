#ifndef ENGINEER_HPP
#define ENGINEER_HPP

#include "Employee.hpp"
#include <string>

class Engineer : public Employee {
public:
    Engineer(const std::string& name, int salary, const std::string& faculty);
    void displayInfo() const override;
    int calculateImpact() const override;
    int getSalary() const override;

private:
    std::string faculty;
};

#endif // ENGINEER_HPP
