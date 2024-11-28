#include "Marketer.hpp"
#include <iostream>

Marketer::Marketer(const std::string& name, int followers)
    : Employee(name, 4500.0), socialMediaFollowers(followers) {}

void Marketer::displayInfo() const {
    std::cout << "Marketer: " << name << ", Salary: " << salary
              << ", Social Media Followers: " << socialMediaFollowers << "\n";
}

int Marketer::calculateImpact() const {
    return socialMediaFollowers / 100;
}
