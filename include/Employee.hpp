#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#include <string>
#include <iostream>

class Employee {
public:
    Employee(const std::string& name, double salary);
    virtual ~Employee() = default;
    virtual void displayInfo() const = 0;
    virtual int calculateImpact() const = 0;
    double getSalary() const;

protected:
    std::string name;
    int salary;
};

#endif // EMPLOYEE_HPP
