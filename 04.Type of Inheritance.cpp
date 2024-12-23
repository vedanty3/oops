#include<iostream>
using namespace std;

// 1. Single Inheritance & Hierarchical Inheritance
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

// 3. Multiple Inheritance
class Engineer {
    public:
        string specialization;
    
    void displaySpecialization() {
        cout<<"I've done "<<this->specialization<<" engineering."<<endl;
    }
};

class Youtuber {
    public:
        int subscribers;

        void contentCreator() {
            cout<<"I've a subscriber base of "<<this->subscribers<<"."<<endl;
        }
};

class YTEducator: public Engineer, public Youtuber{
    public:
        string name;

        YTEducator(string name, string specialization, int subscribers) {
            this->name = name;
            this->specialization = specialization;
            this->subscribers = subscribers;
        }

        void display() {
            cout<<this->name<<" "<<this->specialization<<" "<<this->subscribers<<endl;
            displaySpecialization();
            contentCreator();
        }
};

// 4. Hybrid Inheritance
class LivingBeing {
    public:
        void print() {
            cout<<"I am student."<<endl;
        }
};

class Male {
    public:
        void malePrint() {
            cout<<"I am male."<<endl;
        }
};

class Female {
    public:
        void femalePrint() {
            cout<<"I am female."<<endl;
        }
};

class Boy: public LivingBeing, public Male {
    public:
        void boyPrint() {
            cout<<"I am boy."<<endl;
        }
};

class Girl : public LivingBeing, public Female {
    public:
        void girlPrint() {
            cout<<"I am girl."<<endl;
        }
};

int main() {
    Student s("Vedant Yetekar", 21, 1e5);
    Professor f("John Doe", 35, 2e5);

    s.displayName();
    f.displayName();

    Manager m("James Watson", 3e5, 55, "Software Engineering");
    m.displayDetails();

    YTEducator y("Striver", "CS", 3e5);
    y.display();

    Girl g;
    g.girlPrint();
    g.femalePrint();
    g.print();

    Boy b;
    b.boyPrint();
    b.malePrint();
    b.print();
    
    return 0;
}