#ifndef MARKETER_HPP
#define MARKETER_HPP

#include "Employee.hpp"
#include <string>

class Marketer : public Employee {
public:
    Marketer(const std::string& name, int followers);
    void displayInfo() const override;
    static constexpr double CMkt = 70.0;

private:
    int socialMediaFollowers;
};

#endif
