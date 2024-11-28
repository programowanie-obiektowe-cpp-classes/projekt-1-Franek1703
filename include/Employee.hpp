#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP
#include <string>

class Employee {
public:
    virtual ~Employee() = default;
    virtual void displayInfo() const = 0;
    virtual int calculateImpact() const = 0;
    virtual int getSalary() const = 0;

protected:
    std::string name;
    int salary;
};

#endif // EMPLOYEE_HPP
