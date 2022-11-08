#include <iostream>
using namespace std;

/*
	•	Write a program that creates an Integer Complex class which contains a pair of integers, the first R 
        (represents the real part) and the second I (represents the imaginary part).  The class should contain the 
        following member and friend functions:

	•	Default constructor (sets R=0, I=0) – print message DONE
	•	Parametrized constructor (int Real, int Imag) – print message DONE
	•	Copy constructor( )-print message   DONE
	•	Destructor( ) – print message DONE
	•	Overloaded assignment operator=(const Complex &rhs )  – print message DONE?
	•	Overloaded summation operator+( const Complex &rhs ) – print message DONE
	•	Overloaded difference operator-( const Complex &rhs ) – print message DONE
	•	Overloaded product operator*( const Complex &rhs) – complex product that entails calculating cross multiply terms DONE
	•	Overloaded product operator*( int Real) – scaling a complex number by a Real DONE
	•	friend function output ostream & os operator<<( ostream & os, const Complex &rhs ) – outputs complex number ????
	•	void setValue(int real, int imag) – sets R and I to argument values DONE
	•	This class should contain two private(protected) integer member variables (R,I) that represent a complex number DONE
*/

class Complex{
    int i, r;
    
    public:
    Complex(){
        i = 0;
        r = 0;
        cout << "Complex class created\n";
    }
    Complex(int real, int imag){
        i = imag;
        r = real;
        printf("Real = %i, Imag = %i\n", r, i);
        cout << "Parametrized Complex class created\n";
    }
    ~Complex(){
        cout << "Complex class destructed\n";
    }
    Complex (const Complex &complexCopy){ // copy constructor
		i = complexCopy.i;
		r = complexCopy.r;

		cout << "Complex class copied\n";
	}

    Complex operator = (Complex newComplex){ // not to sure about this one
        Complex newerComplex;
        newerComplex.i = newComplex.i;
        newerComplex.r = newComplex.r;

        return newerComplex;
    }

    Complex operator +(Complex newComplex){
        Complex newerComplex;
        newerComplex.i = i + newComplex.i;
        newerComplex.r = r + newComplex.r;
        
        return newerComplex;
    }

    Complex operator -(Complex newComplex){
        Complex newerComplex;

        newerComplex.i = i - newComplex.i;
        newerComplex.r = r - newComplex.r;
        
        return newerComplex;
    }

    Complex operator * (Complex newComplex){
        Complex newerComplex;
        newerComplex.i = i * newComplex.i;
        newerComplex.r = r*newComplex.r;
        
        return newerComplex;
    }

    Complex operator *(int real){
        Complex newerComplex;
        newerComplex.i = i * real;
        newerComplex.r = r * real;
        
        return newerComplex;
    }

    void setValue(int real, int imag){
        i = imag;
        r = real;
    }

    friend ostream& operator << (ostream& os, const Complex& x);
};

ostream& operator << (ostream& os, const Complex &x){
        os << "Real #: " << x.r << "\tImaginary #: " << x.i << endl;
        return os;
    }

int main() {
    string name = "Fahad Faruqi";
    cout << "------------------------------------------------------------------------------\n"; 
    cout << "Name: " << name << endl;
    cout << "FILE: " << __FILE__ << " DATE: " << __DATE__ << endl;
    cout << "------------------------------------------------------------------------------\n";
    
    
    Complex X_Array[5], Y_Array[5], Z_Array[5];	   //create  complex arrays of 5 complex elements - stack
    
	// X_Array[] = {1,1}, {2,2}, {3,3}, {4,4}, {5,5};
    for (int i = 1; i< 6; i++){ //declaring X values WORKS
        X_Array[i-1].setValue(i,i);
        cout << X_Array[i-1];
    }

    //Y_Array[] = (-1,-1),(-2,-2),(-3,-3)(-4,-4), (-5-,5);
    for (int i = 1; i< 6; i++){
        Y_Array[i-1].setValue(-i,-i);
                cout << X_Array[i-1];

    //Y_Array = (-1,-1),(-2,-2),(-3,-3)(-4,-4), (-5-,5);
    for (int i = -1; i > -6; i--){// declaring Y values WORKS
        Y_Array[i+1].setValue(i,i);
        cout << Y_Array[i+1];
    }

    //	Z_Array[i]  = X_Array[i] + Y_Array[i];  0 <= i <=5
    for (int i = 0; i< 5; i++){
        Z_Array[i] = (X_Array[i]+Y_Array[i]);
    }
    
    cout << "\n**Z_ARRAY VALUES (X+Y)**\n";
    for (int i = 0; i < 5; i++){
        cout << Z_Array[i];
    }
    cout << endl;


    for (int i = 0; i< 5; i++){
        Z_Array[i] = (X_Array[i]*Y_Array[i]);
    }
    
    cout << "\n**Z_ARRAY VALUES (X*Y)**\n";
    for (int i = 0; i < 5; i++){
        cout << Z_Array[i];
    }
    cout << endl;


    for (int i = 0; i< 5; i++){
        Z_Array[i] = (X_Array[i]*10);
    }
    
    cout << "\n**Z_ARRAY VALUES (X*10)**\n";
    for (int i = 0; i < 5; i++){
        cout << Z_Array[i];
    }
    cout << endl;


    cout << (X_Array[1]+Y_Array[2]);
    /*
	Print Z_Array[i]
	Z_Array[i]  = X_Array[i] * Y_Array[i];  0 <= i <=5
	Z_Array[i]
    Z_Array[i]  = X_Array[i] * 10;  0 <= i <=5
    Z_Array[i]
    Z_Array[i]  = 10*X_Array[i];  0 <= i <=5
    Z_Array[i]
    */
}