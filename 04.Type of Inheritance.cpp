#include<iostream>
using namespace std;

// 1. Single Inheritance
class Human {
    protected:
        string name;
        int age;
    public:
        Human(string name, int age) {
            cout<<"Inside Human Constructor."<<endl;
            this->name = name;
            this->age = age;
        }

        void displayName() {
            cout<<"Hello, I'm "<<this->name<<" from Human class."<<endl;
        }

        ~Human() {
            cout<<"Inside Human Destructor."<<endl;
        }
};

class Student : public Human {
    private:
        int fees;
    public:
        Student(string name, int age, int fees): Human(name, age) {
            cout<<"Inside Student Constructor."<<endl;
            this->fees = fees;
        }

        void displayName() {
            cout<<"Hello, I'm "<<this->name<<" from Student class."<<endl;
        }

        ~Student() {
            cout<<"Inside Student Destructor."<<endl;
        }
};

class Professor : public Human {
    private:
        int salary;
    public:
        Professor(string name, int age, int salary): Human(name, age) {
            cout<<"Inside Professor Constructor."<<endl;
            this->salary = salary;
        }

        void displayName() {
            cout<<"Hello, I'm "<<this->name<<" from Professor class."<<endl;
        }

        ~Professor() {
            cout<<"Inside Professor Destructor."<<endl;
        }
};

// 2. Multilevel Inheritance
class Person {
    protected:
        string name;
    public:
        Person(string name) {
            this->name = name;
        }
};

class Employee : public Person {
    protected:
        int salary;
    public:
        Employee(string name, int salary): Person(name) {
            this->salary = salary;
        }
};

class Manager : public Employee {
    protected:
        int employees;
        string department;
    public:
        Manager(string name, int salary, int employees, string department): Employee(name, salary) {
            this->employees = employees;
            this->department = department;
        }

        void displayDetails() {
            cout<<this->name<<endl;
            cout<<this->salary<<endl;
            cout<<this->employees<<endl;
            cout<<this->department<<endl;
        }
};

int main() {
    Student s("Vedant Yetekar", 21, 1e5);
    Professor f("John Doe", 35, 2e5);

    s.displayName();
    f.displayName();

    Manager m("James Watson", 3e5, 55, "Software Engineering");
    m.displayDetails();
    
    return 0;
}