#ifndef LABORER_HPP
#define LABORER_HPP

#include "Employee.hpp"
#include <string>

class Laborer : public Employee {
public:
    Laborer(const std::string& name, double shoeSize);
    void displayInfo() const override;
    static constexpr double CR = 50.0;

private:
    double shoeSize;
};

#endif 
