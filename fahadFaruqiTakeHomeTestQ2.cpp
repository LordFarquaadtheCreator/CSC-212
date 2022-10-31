#include <iostream>
using namespace std;

/*
Write   program that creates a class Shape that contains the following private member data:
	•	int x,y
	•	Color X (R,O,Y,G,B,I,V) – Color is an enumerator data type
	•	static int Cnt – total count of how many shapes exist
	•	int Id (set to Cnt)
             and the usual member functions:
	•	Default Constructor
	•	Parametrized Constructor
	•	Destructor
	•	Copy Constructor
	•	Overloaded assignment operator=( )
	•	Calculate distance( ) from origin (sqrt(x*x+y*y) )
	•	Print( ) – prints the (x,y) coordinates, Color and Id of a specific Shape
	•	The constructors/destructor/copy constructor and assignment operators should provide messages
*/

class Shape {
    int x, y;
    enum Color {R,O,Y,G,B,I,V};
    Color X;
    static int Cnt;
    int *Id = &Cnt;

    public:
    Shape(){
        cout << "Shape constructed\n";
        cout << X;
    }
    
    
};

int main() {
    return 0;
}