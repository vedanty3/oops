#include<iostream>
using namespace std;

class Human {
    protected:
        string name;
        int age;
};

class Engineer: public virtual Human {
    public:
        string specialization;
    
    void displaySpecialization() {
        cout<<"I've done "<<this->specialization<<" engineering."<<endl;
    }
};

class Youtuber: public virtual Human {
    public:
        int subscribers;

        void contentCreator() {
            cout<<"I've a subscriber base of "<<this->subscribers<<"."<<endl;
        }
};

class YTEducator: public Engineer, public Youtuber{
    public:
        YTEducator(string name, int age, string specialization, int subscribers) {
            this->name = name;
            this->age = age;
            this->specialization = specialization;
            this->subscribers = subscribers;
        }

        void display() {
            cout<<this->name<<" "<<this->age<<" "<<this->specialization<<" "<<this->subscribers<<endl;
            displaySpecialization();
            contentCreator();
        }
};


int main() {
    YTEducator y("Striver", 27, "CS", 3e5);
    y.display();



    return 0;
}