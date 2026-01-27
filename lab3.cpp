#include <iostream>

int main() {
    // 1
    class Account {
       public:
        Account(int initialBalance) {
            if (initialBalance < 0) {
                std::cout << "Initial balance is invalid. Setting balance to 0."
                          << std::endl;
                balance = 0;
            } else {
                balance = initialBalance;
            }
        }

        void credit(int amount) {
            if (amount < 0) {
                std::cout << "Credit amount is invalid." << std::endl;
            } else {
                balance += amount;
                std::cout << "Credited: " << amount << std::endl;
            }
        }

        void debit(int amount) {
            if (amount < 0) {
                std::cout << "Debit amount is invalid." << std::endl;
            } else if (amount > balance) {
                std::cout << "Debit amount exceeded account balance."
                          << std::endl;
            } else {
                balance -= amount;
                std::cout << "Debited: " << amount << std::endl;
            }
        }

        int getBalance() {
            return balance;
        }

       private:
        int balance;
    };

    Account account1(100);
    account1.credit(-50);
    account1.debit(200);
    std::cout << "account1 Balance: " << account1.getBalance() << std::endl;
    Account account2(-50);
    account2.credit(150);
    account2.debit(100);
    std::cout << "account2 Balance: " << account2.getBalance() << std::endl;

    // 2
    class Invoice {
       public:
        Invoice(std::string number, std::string description, int quantity,
                int price) {
            partNumber = number;
            partDescription = description;
            if (quantity < 0) {
                std::cout << "Quantity is invalid. Setting quantity to 0."
                          << std::endl;
                partQuantity = 0;
            } else {
                partQuantity = quantity;
            }
            if (price < 0) {
                std::cout << "Price is invalid. Setting price to 0."
                          << std::endl;
                partPrice = 0;
            } else {
                partPrice = price;
            }
        }

        void setNumber(std::string number) {
            partNumber = number;
        }
        void setDescription(std::string description) {
            partDescription = description;
        }
        void setQuantity(int quantity) {
            if (quantity < 0) {
                std::cout << "Quantity is invalid. Leaving quantity unchanged."
                          << std::endl;
            } else {
                partQuantity = quantity;
            }
        }
        void setPrice(int price) {
            if (price < 0) {
                std::cout << "Price is invalid. Leaving price unchanged."
                          << std::endl;
            } else {
                partPrice = price;
            }
        }

        std::string getNumber() {
            return partNumber;
        }
        std::string getDescription() {
            return partDescription;
        }
        int getQuantity() {
            return partQuantity;
        }
        int getPrice() {
            return partPrice;
        }

        int getInvoiceAmount() {
            return partQuantity * partPrice;
        }

       private:
        std::string partNumber;
        std::string partDescription;
        int partQuantity;
        int partPrice;
    };

    Invoice invoice("12345", "Hammer", 10, -5);

    std::cout << "Part Number: " << invoice.getNumber() << std::endl
              << "Part Description: " << invoice.getDescription() << std::endl
              << "Part Quantity: " << invoice.getQuantity() << std::endl
              << "Part Price: " << invoice.getPrice() << std::endl
              << "Invoice Amount: " << invoice.getInvoiceAmount() << std::endl;
    invoice.setNumber("123456");
    invoice.setDescription("Saw");
    invoice.setQuantity(-20);
    invoice.setPrice(15);
    std::cout << "Part Number: " << invoice.getNumber() << std::endl
              << "Part Description: " << invoice.getDescription() << std::endl
              << "Part Quantity: " << invoice.getQuantity() << std::endl
              << "Part Price: " << invoice.getPrice() << std::endl
              << "Invoice Amount: " << invoice.getInvoiceAmount() << std::endl;

    // 3
    class Employee {
       public:
        Employee(std::string first, std::string last, int salary) {
            firstName = first;
            lastName = last;
            if (salary < 0) {
                std::cout << "Salary is invalid. Setting salary to 0."
                          << std::endl;
                monthlySalary = 0;
            } else {
                monthlySalary = salary;
            }
        }

        void setFirstName(std::string first) {
            firstName = first;
        }
        void setLastName(std::string last) {
            lastName = last;
        }
        void setMonthlySalary(int salary) {
            if (salary < 0) {
                // I wouldn't change it but instructions especifically say to
                // set to 0
                std::cout << "Salary is invalid. Setting salary to 0."
                          << std::endl;
                monthlySalary = 0;
            } else {
                monthlySalary = salary;
            }
        }

        std::string getFirstName() {
            return firstName;
        }
        std::string getLastName() {
            return lastName;
        }
        int getMonthlySalary() {
            return monthlySalary;
        }

       private:
        std::string firstName;
        std::string lastName;
        int monthlySalary;
    };

    Employee employee1("John", "Doe", 3000);
    Employee employee2("", "", -4000);
    std::cout << "Employee 1: " << employee1.getFirstName() << " "
              << employee1.getLastName()
              << " - Monthly Salary: " << employee1.getMonthlySalary()
              << std::endl;
    std::cout << "Employee 2: " << employee2.getFirstName() << " "
              << employee2.getLastName()
              << " - Monthly Salary: " << employee2.getMonthlySalary()
              << std::endl;
    employee2.setFirstName("Jane");
    employee2.setLastName("Smith");
    employee2.setMonthlySalary(4500);
    std::cout << "Employee 2: " << employee2.getFirstName() << " "
              << employee2.getLastName()
              << " - Monthly Salary: " << employee2.getMonthlySalary()
              << std::endl;
    std::cout << "Employee 1 Annual Salary: "
              << employee1.getMonthlySalary() * 12 << std::endl;
    std::cout << "Employee 2 Annual Salary: "
              << employee2.getMonthlySalary() * 12 << std::endl;
    employee1.setMonthlySalary(employee1.getMonthlySalary() * 1.1);
    employee2.setMonthlySalary(employee2.getMonthlySalary() * 1.1);
    std::cout << "Employee 1 New Annual Salary: "
              << employee1.getMonthlySalary() * 12 << std::endl;
    std::cout << "Employee 2 New Annual Salary: "
              << employee2.getMonthlySalary() * 12 << std::endl;

    // 4
    class Date {
       public:
        Date(int m, int d, int y) {
            if (m < 1 || m > 12) {
                month = 1;
            } else {
                month = m;
            }
            day = d;
            year = y;
        }

        void setMonth(int m) {
            if (m < 1 || m > 12) {
                month = 1;
            } else {
                month = m;
            }
        }
        void setDay(int d) {
            day = d;
        }
        void setYear(int y) {
            year = y;
        }

        int getMonth() {
            return month;
        }
        int getDay() {
            return day;
        }
        int getYear() {
            return year;
        }

        void displayDate() {
            std::cout << month << "/" << day << "/" << year << std::endl;
        }

       private:
        int month;
        int day;
        int year;
    };

    Date date(13, 27, 2026);
    std::cout << "Date: ";
    date.displayDate();
    date.setMonth(07);
    date.setDay(4);
    date.setYear(2006);
    std::cout << "Updated Date: ";
    date.displayDate();
}