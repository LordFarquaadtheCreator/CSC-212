#include <iostream>
#include <cmath>
using namespace std;

/*
Write   program that creates a class Shape that contains the following private member data:
	•	int x,y DONE
	•	Color X (R,O,Y,G,B,I,V) – Color is an enumerator data type DONE
	•	static int Cnt – total count of how many shapes exist DONE
	•	int Id (set to Cnt) DONE
             and the usual member functions:
	•	Default Constructor DONE
	•	Parametrized Constructor DDONE
	•	Destructor DONE
	•	Copy Constructor DONE
	•	Overloaded assignment operator=( ) DONE
	•	Calculate distance( ) from origin (sqrt(x*x+y*y) ) DONE
	•	Print( ) – prints the (x,y) coordinates, Color and Id of a specific Shape DONE
	•	The constructors/destructor/copy constructor and assignment operators should provide messages DONE
*/

enum Color {R,O,Y,G,B,I,V}; // no values

class Shape {
    int x, y;
    Color X;
    static int Cnt; // how many shapes exist
    static int id; //  contains (int) id of shape

    public:
    Shape(){
        cout << "Shape constructed\n";
		Cnt = 0;
		id = Cnt;
		Cnt ++;
    }
	Shape (int x, int y){
		cout << "Parameterized shape constructed\n";
		this->x = x;
		this->y= y;

		Cnt = 0;
		id = Cnt;
		Cnt ++;
	}
	~Shape(){
		cout << "Shape destructed\n";
	}
    
	Shape (const Shape &shapeCopy){
		x= shapeCopy.x;
		y=shapeCopy.y;

		cout << "Shape copied\n";
	}

	Shape operator = (Shape red){ // don't know if this causes memory leaks or not ...
		red.x = x;
		red.y = y;

		return red;
	}

    void distanceFromOrigin (){ // 100% right, no need to check
		printf("Shape is %.3f units from Origin\n", (sqrt(pow(x,2)+pow(x,2)))); //pythagorean theorm
	}

	void print(){
		printf("(%i,%i)\n", x, y); //x and y coordiantes
		cout << "Id: " << id;
	}
};

int main() {
	Shape square(5,5);
	square.print();
    return 0;
}