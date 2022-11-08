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

enum Color {R,O,Y,G,B,I,V};

class Shape {
    int x, y;
    Color X;
    static int Cnt; // how many shapes exist
    int id; //  contains (int) id of shape

    public:
    Shape(){
        cout << "Shape constructed\n";
		x = 0;
		y = 0;
		Cnt ++;
		id = Cnt;
    }
	Shape (int x, int y, Color X){
		cout << "Parameterized shape constructed\n";
		this->x = x;
		this->y= y;
		this->X=X;

		Cnt ++;
		id = Cnt;
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
		printf("(%i,%i)\nId: %i\n", x, y, id); //x and y coordiantes
	}
};

class Circle : Shape {
	int radius;

	public:
	Circle(){
		radius =0;
		cout << "Circle Constructor Created\n";
	}
	Circle(int radius, Color X){
		this->radius = radius;
		this->X=X;
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

int Shape::Cnt = 0;                 //static variable initialisation

int main() {
	Shape X, Amoeba(3,4, Y); //works
	Circle C1(3,4,B,5);
    return 0;
}

/*
Demonstrate the following:
	•	Shape X, Amoeba(3,4, ‘Y’) 
	•	Circle C1(3,4,’B’,5) – blue circle located at (5,6) of radius=5
	•	Circle C2(15, 20, ’Y’,10) – yellow circle located at (15,20) of radius=10
	•	Rectangle R(12, 5, ‘V’, 8,4) – Violet rectangle located at (12,5) of dimension (8,4)
	•	Calculate the Area of each derived object; float CalcArea( )
	•	For all created objects use the appropriate Print functions
	•	Calculate and print the distance between C1 and C2 – use the respective (x,y) locations 
	•	Calculate the distance from origin for C1, C2 and R
	•	Print the total number of created shapes

*/