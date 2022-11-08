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
    
	Shape (const Shape &shapeCopy){ // copy constructor
		x= shapeCopy.x;
		y=shapeCopy.y;

		cout << "Shape copied\n";
	}

	Shape operator = (Shape red){ // don't know if this causes memory leaks or not ...
		red.x = x;
		red.y = y;

		return red;
	}

    float distanceFromOrigin (){ // 100% right, no need to check
		return (sqrt(pow(x,2)+pow(x,2))); //pythagorean theorm
	}

	void print(){
		printf("(%i,%i)\n", x, y); //x and y coordiantes
		cout << "Id: " << id;
	}
};

class Circle : Shape {
	int radius;

	public:
	Circle(){
		radius =0;
		cout << "Circle Constructor Created\n";
	}
	Circle(int radius){
		this->radius = radius;
		cout << "Circle Parametrized Constructor Created\n";
	}
	Circle (const Circle &Circlecopy){
		radius= Circlecopy.radius;
		cout << "Circle copied\n";
	}

	Circle operator = (Circle red){
		red.radius = radius;

		return red;
	}

	float CalcArea(){ //simple geometry
		return (pow(radius,2)*3.14);
	}

	void print(){
		printf("Radius: %i, Area: %.2f", radius, CalcArea());
	}
};

class Rectangle : Shape {
	int Len, Width;

	public:
	Rectangle(){
		Len =0;
		Width = 0;
		cout << "Rectangle Constructor Created\n";
	}
	Rectangle(int Len, int Width){
		this->Len = Len;
		this->Width= Width;
		cout << "Rectangle Parametrized Constructor Created\n";
	}
	Rectangle (const Rectangle &rectangleCopy){
		Len= rectangleCopy.Len;
		Width=rectangleCopy.Width;
		cout << "Rectangle copied\n";
	}

	Rectangle operator = (Rectangle red){
		red.Width = Width;
		red.Len = Len;

		return red;
	}

	float CalcArea(){ //simple geometry
		return Len*Width;
	}

	void print(){
		printf("Lenght: %i, Width: %i, Area: %.2f", Len, Width, CalcArea());
	}
};

int main() {
	Shape square(5,5);
	square.print();
    return 0;
}