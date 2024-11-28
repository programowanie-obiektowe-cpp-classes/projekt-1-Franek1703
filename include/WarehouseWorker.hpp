#ifndef WAREHOUSE_WORKER_HPP
#define WAREHOUSE_WORKER_HPP
#include "Employee.hpp"
#include <string>

class WarehouseWorker : public Employee {
public:
    WarehouseWorker(const std::string& name, bool hasForkliftLicense);
    void displayInfo() const override;
    int calculateImpact() const override;

private:
    bool forkliftCertified;
};

#endif
