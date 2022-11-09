#include <iostream>
using namespace std;


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

    Complex operator +(Complex newComplex){
        Complex temp;
        temp.i = i + newComplex.i;
        temp.r = r + newComplex.r;
        
        return temp;
    }

    Complex operator -(Complex newComplex){
        Complex temp;

        temp.i = i - newComplex.i;
        temp.r = r - newComplex.r;
        
        return temp;
    }

    Complex operator *(Complex newComplex){ // needs to be special since we have complex numbers 
        // using formula (a+bi)(c+di) = (ac-bd)+(ad+bc)i
        // translates to   (r+ji)(r2+j2i2) = (r*r2-j*j2)+(r*j2+j*r2)i
        // newComplex is our (c+di)
        Complex temp;

        temp.i = (r*newComplex.i + i*newComplex.r);
        temp.r = (r*newComplex.r-i*newComplex.i);
        return temp;
    }

    Complex operator *(int real){
        Complex temp;
        temp.i = i * real;
        temp.r = r * real;
        
        return temp;
    }

    void setValue(int real, int imag){
        i = imag;
        r = real;
    }

    friend ostream& operator << (ostream& os, const Complex& x);
    friend Complex operator*(int x, Complex temp);
};

ostream& operator << (ostream& os, const Complex &x){
    os << "Real #: " << x.r << "\tImaginary #: " << x.i << endl;
    return os;
}
Complex operator*(int x, Complex temp){
    Complex tempTemp;

    tempTemp.i = temp.i*x;
    tempTemp.r = temp.r*x;
    return tempTemp;
}



int main() {
    string name = "Fahad Faruqi";
    cout << "------------------------------------------------------------------------------\n"; 
    cout << "Name: " << name << endl;
    cout << "FILE: " << __FILE__ << "\tDATE: " << __DATE__ << endl;
    cout << "------------------------------------------------------------------------------\n";
    
    
    Complex X_Array[5], Y_Array[5], Z_Array[5];	   //create  complex arrays of 5 complex elements - stack
    
	// X_Array[] = {1,1}, {2,2}, {3,3}, {4,4}, {5,5};
    for (int i = 1; i< 6; i++){ //declaring X values WORKS
        X_Array[i-1].setValue(i,i);
    }

    for (int i = 1; i < 6; i++){// declaring Y values
        Y_Array[i-1].setValue(-i,-i);
    }


    //	Z_Array[i]  = X_Array[i] + Y_Array[i];  0 <= i <=5
    for (int i = 0; i< 5; i++){
        Z_Array[i] = (X_Array[i]+Y_Array[i]);
    }
    
    cout << "\n**Z_ARRAY VALUES (X+Y)**\n"; //WORKS
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

    // // Z_Array values * 10
    for (int i = 0; i< 5; i++){
        Z_Array[i] = (X_Array[i]*10);
    }
    
    cout << "\n**Z_ARRAY VALUES (X*10)**\n";
    for (int i = 0; i < 5; i++){
        cout << Z_Array[i];
    }
    cout << endl;

    // // Z_Array values * 10
    for (int i = 0; i< 5; i++){
        Z_Array[i] = (10*X_Array[i]);
    }
    
    cout << "\n**Z_ARRAY VALUES (10*X)**\n";
    for (int i = 0; i < 5; i++){
        cout << Z_Array[i];
    }
    cout << endl;


    Complex heap[3];
    for (int i = 0; i < 3; i++){
        heap[i].setValue(3*i,-3*i);
    }
    cout << "\n**NEW ARRAY ON HEAP VALUES**\n";
    for (int i = 0; i < 3; i++){
        cout << heap[i];
    }
    cout << endl;

    }