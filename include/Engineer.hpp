#ifndef ENGINEER_HPP
#define ENGINEER_HPP

#include "Employee.hpp"
#include <string>

class Engineer : public Employee {
public:
    Engineer(const std::string& name, const std::string& faculty);
    void displayInfo() const override;
    static constexpr double CI = 200.0;


private:
    std::string faculty;
};

#endif
