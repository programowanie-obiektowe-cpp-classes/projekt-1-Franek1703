#include "Engineer.hpp"
#include <iostream>

Engineer::Engineer(const std::string& name, const std::string& faculty) : Employee(name, 5000.0), faculty(faculty) {}

void Engineer::displayInfo() const {
    std::cout << "Engineer: " << name << ", Salary: " << salary
              << ", Faculty: " << faculty << "\n";
}
