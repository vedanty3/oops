#include<iostream>
#include<math.h>
using namespace std;

// Function Overloading
class Area {
    public:
        float calculateArea(float r) {
            return (M_PI*r*r*1.0);
        }
        
        float calculateArea(float length, float breadth) {
            return length*breadth;
        }
};

// Operator Overloading
class Complex {
    private:
        int real, img;
        
    public:
        Complex() {
            
        }
        
        Complex(int real, int img) {
            this->real = real;
            this->img = img;
        }
        
        void display() {
            cout<<real<<" + i"<<img<<endl;
        }
        
        Complex operator +(Complex &c) {
            Complex ans;
            // even if real and img are private members, we have access to private members with the object of same class
            ans.real = real + c.real;
            ans.img = img + c.img;
            return ans;
        }
};

int  main() {
    Area area;
    // It figures out in compile time which function to call based on the passed arguments
    cout<<area.calculateArea(3)<<endl;
    cout<<area.calculateArea(2, 3)<<endl;
    
    Complex c1(3, 2), c2(4, 3);
    
    c1.display();
    c2.display();
    
    Complex c3 = c1 + c2;
    
    c3.display();
    
    return 0;
}