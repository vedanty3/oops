#include<iostream>
using namespace std;

//           External Code - Within Class - Derived Class
// Public     true ------------- true ------------- true
// Private    false ------------- true ------------- false
// Protected  false ------------- true ------------- true


// Public -> Public = Public
// Public -> Private = Private
// Public -> Protected = Protected

// Private -> Public = X
// Private -> Protected = X 
// Private -> Private = X

// Protected -> Public = Protected
// Protected -> Protected = Protected
// Protected -> Private = Private


class Human {
    private:
        int age;
    protected:
        bool hasDisease;
    public:
        string name;
        
        Human(int age, bool hasDisease, string name) {
            this->age = age;
            this->hasDisease = hasDisease;
            this->name = name;
        }
};

class Student : public Human {
    public:
        int fees;
        
        Student(int age, bool hasDisease, string name, int fees): Human(age, hasDisease, name) {
            this->fees = fees;
        }
};

int main() {
    Student s(21, false, "Vedant Yetekar", 100000);
    cout<<s.name<<endl; // public
    // cout<<s.age<<endl; // private
    // cout<<"Have any disease ?"<<endl;
    // cout<<"Answer: "<<(s.hasDisease ? "Yes" : "No")<<endl; // protected
    cout<<s.fees<<endl; // public
    return 0;
}


