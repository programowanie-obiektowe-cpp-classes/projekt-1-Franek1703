#include "WarehouseWorker.hpp"
#include <iostream>

WarehouseWorker::WarehouseWorker(const std::string& name, int salary, bool forklift)
    : forkliftCertified(forklift) {
    this->name = name;
    this->salary = salary;
}

void WarehouseWorker::displayInfo() const {
    std::cout << "Warehouse Worker: " << name << ", Salary: " << salary
              << ", Forklift Certified: " << (forkliftCertified ? "Yes" : "No") << "\n";
}

int WarehouseWorker::calculateImpact() const {
    return 5;
}

int WarehouseWorker::getSalary() const {
    return salary;
}
