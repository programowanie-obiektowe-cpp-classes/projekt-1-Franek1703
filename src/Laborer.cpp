#include "Laborer.hpp"
#include <iostream>

Laborer::Laborer(const std::string& name, double shoeSize)
    : Employee(name, 3000.0), shoeSize(shoeSize) {}

void Laborer::displayInfo() const {
    std::cout << "Worker: " << name << ", Salary: " << salary
              << ", Shoe Size: " << shoeSize << "\n";
}

