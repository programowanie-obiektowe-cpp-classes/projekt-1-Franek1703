#include "Marketer.hpp"
#include <iostream>

Marketer::Marketer(const std::string& name, int salary, int followers)
    : socialMediaFollowers(followers) {
    this->name = name;
    this->salary = salary;
}

void Marketer::displayInfo() const {
    std::cout << "Marketer: " << name << ", Salary: " << salary
              << ", Social Media Followers: " << socialMediaFollowers << "\n";
}

int Marketer::calculateImpact() const {
    return socialMediaFollowers / 100;
}

int Marketer::getSalary() const {
    return salary;
}
