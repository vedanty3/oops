#include<iostream>
#include<exception>
using namespace std;

class Customer {
    private:
        string name;
        int balance, account_number;
    
    public:
        Customer(string name, int balance, int account_number) {
            this->name = name;
            this->balance = balance;
            this->account_number = account_number;
        }

        void deposit(int amount) {
            if(amount>0) {
                balance += amount;
                cout<<amount<<" is credited to your account."<<endl;
            } else {
                throw "Amount should be greater than 0.";
            }
        }

        void withdraw(int amount) {
            if(amount>0 and amount<=balance) {
                balance -= amount;
                cout<<amount<<" is debited from your account."<<endl;
            } else if(amount<0) {
                throw "Amount should be greater than 0.";
            } else {
                throw "Insufficient balance.";
            }
        }
};

int main() {
    Customer c("Vedant Yetekar", 2e5, 30);

    try {
        c.deposit(10000);
        c.deposit(2e6);
        c.withdraw(1e7);
    } catch(const char *e) {
        cout<<"Exception occured: "<<e<<endl;
    }

    try {
        int a = 4;
        int b = 0;
        if(b==0) {
            throw "Divide by zero not possible.";
        }
        int ans = a/b;
        cout<<ans<<endl;
    } catch(const char *e) {
        cout<<"Exception occured: "<<e<<endl;
    }

    try {
        int *arr = new int[1000000000000];
        cout<<"Memory allocation is successfull."<<endl;
        delete []arr;
    } catch(const bad_alloc &e) {
        cout<<"Exception occured: "<<e.what()<<endl;
    }

    return 0;
}