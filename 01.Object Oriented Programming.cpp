#include<iostream>
using namespace std;

// class is a user defined data type, it is a blueprint for an object
class Student {
    // access modifiers: public, private, protected
    private:
        // attributes
        string name;
        int age, rno;
        char grade;

    public:
    // setter functions
    void setName(string name) {
        if(name.size()==0) {
            cout<<"Invalid Name !"<<endl;
            return;
        }
        this->name = name;
    }

    void setAge(int age) {
        if(age<=0) {
            cout<<"Invalid Age !"<<endl;
            return;
        }
        this->age = age;
    }

    void setRollNo(int rno) {
        if(rno<=0) {
            cout<<"Invalid Age !"<<endl;
            return;
        }
        this->rno = rno;
    }

    void setGrade(char grade) {
        this->grade = grade;
    }

    // getter functions
    string getName() {
        return this->name;
    }

    int getAge() {
        return this->age;
    }

    int getRollNo() {
        return this->rno;
    }

    char getGrade() {
        cout<<"Enter pin to view grade: ";;
        string pin;
        cin>>pin;
        if(pin!="1234") {
            cout<<"Enter a valid pin"<<endl;
            return ' ';
        }
        return this->grade;
    }
};

int main() {
    Student s1;
    s1.setName("Vedant Yetekar");
    s1.setAge(21);
    s1.setRollNo(30);
    s1.setGrade('O');

    cout<<"Name: "<<s1.getName()<<endl;
    cout<<"Age: "<<s1.getAge()<<endl;
    cout<<"Roll No: "<<s1.getRollNo()<<endl;
    cout<<"Grade: "<<s1.getGrade()<<endl;

    return 0;
}