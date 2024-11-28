#include "WarehouseWorker.hpp"
#include <iostream>

WarehouseWorker::WarehouseWorker(const std::string& name, bool hasForkliftLicense)
    : Employee(name, 4000.0), forkliftCertified(hasForkliftLicense) {}

void WarehouseWorker::displayInfo() const {
    std::cout << "Warehouse Worker: " << name << ", Salary: " << salary
              << ", Forklift Certified: " << (forkliftCertified ? "Yes" : "No") << "\n";
}

int WarehouseWorker::calculateImpact() const {
    return 5;
}