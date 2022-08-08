#include <iostream>
#include <string>

// Pattern studies: interface

class SalaryCalculator {
public:
    //every child class must implement getSalary
    virtual double getSalary() = 0;
};

class Developer : public SalaryCalculator {
private:
    std::string name;
    double baseSalary = 2500.0;
    double overtimeHours = 0;
    double dollarsPerOvertimeHour = 50;
public:
    Developer(std::string name) {
        name = name;
    }
    void setExtraHours(double value) {
        overtimeHours = value;
    }
    // implemented
    double getSalary() {
        return baseSalary + (dollarsPerOvertimeHour * overtimeHours);
    }
};

class Salesperson : public SalaryCalculator {
private:
    std::string name;
    int salespersonLevel = 1;
    double baseSalary = 1100.0;
    double monthlySales = 0;
    double commision = 0;
public:
    Salesperson(std::string name, int level) {
        name = name;
        setSalespersonLevel(level);
    }
    void setSalespersonLevel(int level) {
        switch (level) {
        case 3:
            commision = 0.15;
            salespersonLevel = level;
            break;
        case 2:
            commision = 0.08;
            salespersonLevel = level;
            break;
        case 1:
        default:
            commision = 0.01;
            salespersonLevel = 1;
        }
    }
    void setMonthlySales(double value) {
        monthlySales = value;
    }
    // implemented
    double getSalary() {
        return baseSalary + (monthlySales * commision);
    }
};

