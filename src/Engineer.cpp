#include "Engineer.hpp"
#include <iostream>

Engineer::Engineer(const std::string& name, int salary, const std::string& faculty)
    : faculty(faculty) {
    this->name = name;
    this->salary = salary;
}

void Engineer::displayInfo() const {
    std::cout << "Engineer: " << name << ", Salary: " << salary
              << ", Faculty: " << faculty << "\n";
}

int Engineer::calculateImpact() const {
    return 10;
}

int Engineer::getSalary() const {
    return salary;
}
