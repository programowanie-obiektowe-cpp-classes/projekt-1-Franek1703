#include "Laborer.hpp"
#include <iostream>

Laborer::Laborer(const std::string& name, int salary, double shoeSize)
    : shoeSize(shoeSize) {
    this->name = name;
    this->salary = salary;
}

void Laborer::displayInfo() const {
    std::cout << "Worker: " << name << ", Salary: " << salary
              << ", Shoe Size: " << shoeSize << "\n";
}

int Laborer::calculateImpact() const {
    return static_cast<int>(shoeSize * 2); // Wpływ proporcjonalny do rozmiaru buta
}

int Laborer::getSalary() const {
    return salary;
}
