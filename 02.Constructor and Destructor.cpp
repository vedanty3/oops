#include<iostream>
using namespace std;

class Customer {
    private:
        string name;
        int account_number;
        int balance;
        int *data;
        int id;
        
    public:
        static int total_customers;

        // Constructor Overloading
        Customer() {
            data = new int;
            *data = 10;
            cout<<"Inside Default Constructor"<<endl;
            ++total_customers;
            this->id = total_customers;
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
        }

        // Destructor gets called in reverse order
        ~Customer() {
            delete data;
            cout<<"Inside Destructor "<<this->id<<endl;
        }

        void displayDetails() {
            cout<<this->name<<" "<<this->account_number<<" "<<this->balance<<endl;
        }
};

int Customer::total_customers = 0;

int main() {
    Customer c1("Vedant Yetekar", 1, 1e9);
    Customer c2("John Doe", 2);
    Customer c3("Jessica");
    Customer c4;
    Customer c5(c1);

    // Assignment Operator
    c2 = c3;

    c1.displayDetails();
    c2.displayDetails();
    c3.displayDetails();
    c4.displayDetails();
    c5.displayDetails();

    return 0;
}