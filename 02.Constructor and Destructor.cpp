#include<iostream>
using namespace std;

class Customer {
    private:
        int id;
        int *data;
        string name;
        int balance;
        int account_number;
        static int total_balance;
        static int total_customers;
        
    public:
        // Constructor Overloading
        Customer() {
            data = new int;
            *data = 10;
            cout<<"Inside Default Constructor"<<endl;
            ++total_customers;
            this->id = total_customers;
        }

        void deposit(int amount) {
            if(amount>0) {
                balance += amount;
                total_balance += amount;
            }
        }

        void withdraw(int amount) {
            if(amount<=balance and amount>0) {
                balance -= amount;
                total_balance -= amount;
            }
        }

        inline Customer(string name): name(name) {
            data = new int;
            *data = 10;
            cout<<"Inside Inline Constructor"<<endl;
            ++total_customers;
            this->id = total_customers;
        } 

        Customer(string name, int account_number) {
            data = new int;
            *data = 10;
            this->name = name;
            this->account_number = account_number;
            this->balance = 1e5;
            ++total_customers;
            this->id = total_customers;
        }

        Customer(string name, int account_number, int balance) {
            cout<<"Inside Parameterised Constructor"<<endl;
            data = new int;
            *data = 10;
            this->name = name;
            this->account_number = account_number;
            this->balance = balance;
            ++total_customers;
            this->id = total_customers;
        }

        // Copy Constructor
        Customer(Customer &c) {
            cout<<"Inside Copy Constructor"<<endl;
            this->name = c.name;
            this->account_number = c.account_number;
            this->balance = c.balance;
            ++total_customers;
            this->id = total_customers;
            total_balance += balance;
        }

        // Destructor gets called in reverse order
        ~Customer() {
            delete data;
            cout<<"Inside Destructor "<<this->id<<endl;
        }

        void displayDetails() {
            cout<<this->name<<" "<<this->account_number<<" "<<this->balance<<endl;
        }

        void static displayTotalCustomers() {
            cout<<total_customers<<endl;
        }

        void static displayTotalBalance() {
            cout<<total_balance<<endl;
        }
};

int Customer::total_customers = 0;
int Customer::total_balance = 0;

int main() {
    Customer c1("Vedant Yetekar", 1, 1e9);
    Customer c2("John Doe", 2);
    Customer c3("Jessica");
    Customer c4;
    Customer c5(c1);
    Customer *c6 = new Customer(c1);

    // Assignment Operator
    c2 = c3;

    c1.displayDetails();
    c2.displayDetails();
    c3.displayDetails();
    c4.displayDetails();
    c5.displayDetails();
    c6->displayDetails();

    Customer::displayTotalCustomers();

    c1.deposit(1000);
    c1.withdraw(1000000500);

    Customer::displayTotalBalance();

    delete c6;

    return 0;
}