#ifndef WAREHOUSE_WORKER_HPP
#define WAREHOUSE_WORKER_HPP
#include "Employee.hpp"
#include <string>

class WarehouseWorker : public Employee {
public:
    WarehouseWorker(const std::string& name, bool hasForkliftLicense);
    void displayInfo() const override;
    static constexpr double CMag = 100.0;

private:
    bool forkliftCertified;
};

#endif
