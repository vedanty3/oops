#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

// Polymorphism
// 1. Compile Time Polymorphism
// a. Function Overloading
class Area {
	public:
      float calculateArea(float r) {
          return (M_PI * r * r * 1.0);
      }
    
      float calculateArea(float length, float breadth) {
          return length * breadth;
      }
};

// b. Operator Overloading
class Complex {
	private:
      int real, img;
	
    public:
      Complex() {
      }
  
      Complex(int real, int img) {
          this-> real = real;
          this-> img = img;
      }
  
      void display() {
          cout << real << " + i" << img << endl;
      }
  
	Complex operator + (Complex & c) {
		Complex ans;
		// even if real and img are private members, we have access to private members with the object of same class
		ans.real = real + c.real;
		ans.img = img + c.img;
		return ans;
	}
};

// 2. Runtime Polymorphism
// a. Virtual Function
class Animal {
	public: virtual void makeNoise() {
		cout << "Hu Hu" << endl;
	}
};

class Dog: public Animal {
	public:
		// Function Overriding
		void makeNoise() {
			cout << "Bark" << endl;
		}
};

class Cat: public Animal {
	public:
        void makeNoise() {
    		cout << "Meow" << endl;
        }
};

// b. Pure Virtual Function (Abstract Class)
// Can't create an object of this class
class Vehicle {
	public: virtual void startEngine() = 0;
};

class Bike: public Animal {
	public:
		// It has to be overwritten
		void startEngine() {
			cout << "Bike started" << endl;
		}
};

int main() {
	Area area;
	// It figures out in compile time which function to call based on the passed arguments
	cout << area.calculateArea(3) << endl;
	cout << area.calculateArea(2, 3) << endl;
  
	Complex c1(3, 2), c2(4, 3);
	c1.display();
	c2.display();
  
	Complex c3 = c1 + c2;
	c3.display();
  
	// Animal *animal;
	// animal = new Dog();
	// animal->makeNoise();
	vector<Animal*>animals;
  
	animals.push_back(new Dog());
	animals.push_back(new Cat());
	animals.push_back(new Dog());
	animals.push_back(new Cat());
	animals.push_back(new Cat());
  
	for(auto & animal: animals) {
		animal->makeNoise();
	}
  
	return 0;
}