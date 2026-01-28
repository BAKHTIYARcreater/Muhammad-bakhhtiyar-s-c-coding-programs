#include <iostream>
using namespace std;

/*
  Class: Complex
  Purpose: To represent a complex number and demonstrate
           the use of a copy constructor with dynamic memory
*/
class Complex {
private:
    // Pointers used because memory must be allocated dynamically
    double* real;   // stores address of real part
    double* imag;   // stores address of imaginary part

public:
    /*
      Constructor
      Allocates memory in heap and initializes values
    */
    Complex(double r = 0, double i = 0) {
        real = new double;   // dynamic allocation
        imag = new double;

        *real = r;           // assign values
        *imag = i;
    }

    /*
      Copy Constructor
      Creates a new object by copying data from another object
      Performs deep copy (separate memory allocation)
    */
    Complex(const Complex& c) {
        real = new double;        // allocate new memory
        imag = new double;

        *real = *(c.real);        // copy value, not address
        *imag = *(c.imag);
    }

    /*
      Display function
      Prints the complex number
    */
    void display() {
        cout << *real << " + " << *imag << "i" << endl;
    }

    /*
      Destructor
      Frees dynamically allocated memory
    */
    ~Complex() {
        delete real;
        delete imag;
    }
};

int main() {
    // Create first object
    Complex c1(4, 6);

    // Create second object using copy constructor
    Complex c2 = c1;

    cout << "First Object: ";
    c1.display();

    cout << "Second Object (Copied): ";
    c2.display();

    return 0;
}

