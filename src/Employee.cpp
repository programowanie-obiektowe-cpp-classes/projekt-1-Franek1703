#include "Employee.hpp"

Employee::Employee(const std::string& name, double salary)
    : name(name), salary(salary) {}

double Employee::getSalary() const
{
    return salary;
}
