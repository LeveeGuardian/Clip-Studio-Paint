#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class Employee {
public:
    Employee(const std::string& name, double salary)
        : name(name), salary(salary) {}

    const std::string& getName() const {
        return name;
    }

    double getSalary() const {
        return salary;
    }

private:
    std::string name;
    double salary;
};

class Payroll {
public:
    void addEmployee(const std::string& name, double salary) {
        employees.emplace_back(name, salary);
    }

    double getTotalSalary() const {
        double total = 0.0;

        for (const auto& employee : employees) {
            total += employee.getSalary();
        }

        return total;
    }

    void printReport() const {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Payroll Report\n";
        std::cout << "==============\n";

        for (const auto& employee : employees) {
            std::cout << employee.getName()
                      << " | $"
                      << employee.getSalary()
                      << '\n';
        }

        std::cout << "==============\n";
        std::cout << "Total Payroll: $" << getTotalSalary() << '\n';
    }

private:
    std::vector<Employee> employees;
};

int main() {
    Payroll payroll;

    payroll.addEmployee("Alice", 4200.00);
    payroll.addEmployee("Brian", 3850.50);
    payroll.addEmployee("Clara", 5100.75);
    payroll.addEmployee("David", 3600.25);

    payroll.printReport();

    return 0;
}