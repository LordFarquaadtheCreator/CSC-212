
//Points off:  (-13)

#include <iostream>
#include <cmath> //needed to make life easier
using namespace std;


enum Color {R,O,Y,G,B,I,V}; // global declaration		//ok

class Shape {
    int x, y;							//ok
    Color X;
    static int Cnt; // how many shapes exist			//ok
    int id; //  contains (int) id of shape

    public:
    Shape(){
        cout << "Shape constructed\n";
		x = 0;
		y = 0;

		id = Cnt;
		Cnt ++;						//ok
    }
	Shape (int x, int y, Color X){
		cout << "Parameterized shape constructed\n";
		this->x = x;
		this->y= y;
		this->X=X;

		id = Cnt;
		Cnt ++;						//ok
	}
	~Shape(){
		cout << "Shape destructed\n";
		//Cnt--;			//decrement on removal    (-2)
	} 
	Shape (const Shape &shapeCopy){ // copy constructor
		x= shapeCopy.x;
		y=shapeCopy.y;

		cout << "Shape copied\n";
		//Cnt++;		//created object needs to be included  (-1)
	}
	Shape operator = (Shape red){ // don't know if this causes memory leaks or not ...
	//if(this != &rhs){		standard code 			(-2)
		red.x = x;
		red.y = y;
	}
		return red;
	}

    float distanceFromOrigin (){ // 100% right, no need to check
		return (sqrt(pow(x,2)+pow(x,2))); //pythagorean theorm
	}

	void print(){
		printf("(%i,%i)\nId: %i\n", x, y, id); //x and y coordiantes
	}

	friend class Circle;			//unnecessary - derived classes
	friend class Rectangle;			//			(-2)
	friend void distance(Shape x, Shape y);
	friend void printTotalShapes(Shape x);
};

class Circle : public Shape {					//ok
	int radius;						//ok

	public:
	Circle(){			//missing Shape()       (-2)
		radius =0;
		cout << "Circle Constructor Created\n";
	}
	//Circle(int x, int y, Color X, int radius){	//
	Circle(int x, int y, Color X, int radius):Shape(x,y, X){	//   (-2)
		this->x = x;
		this->y= y;
		this->X=X;
		this->radius = radius;
		cout << "Circle Parametrized Constructor Created\n";
	}
	~Circle(){
		cout << "Circle destructed\n";			//ok
	} 
	Circle (const Circle &Circlecopy){		//missing Shape part   (-1)
		radius= Circlecopy.radius;
		cout << "Circle copied\n";
	}

	Circle operator = (Circle red){
	//if(this != & red){		//standard code			(-2)
		red.radius = radius;
	//}

		return red;
	}

	float CalcArea(){ //simple geometry
		return (pow(radius,2)*3.141594);
	}

	void print(){
		printf("(%i,%i)\nId: %i\n", x, y, id); //x and y coordiantes
		printf("Radius: %i, Area: %.2f\n", radius, CalcArea());
	}
};

class Rectangle : public Shape {			//ok
	int Len, Width;

	public:
	Rectangle(){
		Len =0;
		Width = 0;
		cout << "Rectangle Constructor Created\n";
	}
	Rectangle(int x, int y, Color X, int Len, int Width){
		this->x = x;
		this->y= y;
		this->X=X;
		this->Len = Len;
		this->Width= Width;
		cout << "Rectangle Parametrized Constructor Created\n";
	}
	~Rectangle(){
		cout << "Rectangle destructed\n";
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
		printf("(%i,%i)\nId: %i\n", x, y, id); //x and y coordiantes
		printf("Lenght: %i, Width: %i, Area: %.2f\n", Len, Width, CalcArea());
	}
};

void distance(Shape x, Shape y){
	printf("The distance between the two shapes is: %.2f\n", sqrt(pow(y.x-x.x, 2)+pow(y.y-x.y,2))); // distance formula 
}

void printTotalShapes(Shape x){
	printf("The total number of shapes are: %i\n", x.Cnt);
}

int Shape::Cnt = 0;                 //static variable initialisation
// ID starts from 0
int main() {
	string name = "Fahad Faruqi";
    cout << "------------------------------------------------------------------------------\n"; 
    cout << "Name: " << name << endl;
    cout << "FILE: " << __FILE__ << " DATE: " << __DATE__ << endl;
    cout << "------------------------------------------------------------------------------\n";

	Shape X, Amoeba(3,4, Y); //works
	Circle C1(3,4,B,5); // works
	Circle C2(15, 20, Y,10);
	Rectangle R(12, 5, V, 8,4);

	printf("\n**AREA**\nX: N/A\nAmoeba: N/A\nC1: %.2f\nC2: %.2f\nR: %.2f\n\n", C1.CalcArea(), C2.CalcArea(), R.CalcArea());
	
	cout << "**INFO**\n";
	X.print();
	Amoeba.print();
	C1.print();
	C2.print();
	R.print();
	cout << endl;

	cout << "**DISTANCES**\n";
	distance(C1, C2);
	printf("Distance from Origin for C1: %.2f\n",  C1.distanceFromOrigin());
	printf("Distance from Origin for C2: %.2f\n", C2.distanceFromOrigin());
	printf("Distance from Origin for R: %.2f\n", R.distanceFromOrigin());
	cout << endl;
	
	cout << "**TOTAL SHAPES**" << endl;
	printTotalShapes(R);
	cout << endl;

    return 0;
}
/***************
./a.out
------------------------------------------------------------------------------
Name: Fahad Faruqi
FILE: T1P2_Faruqi.cpp DATE: Nov 20 2022
------------------------------------------------------------------------------
Shape constructed
Parameterized shape constructed
Shape constructed
Circle Parametrized Constructor Created
Shape constructed
Circle Parametrized Constructor Created
Shape constructed
Rectangle Parametrized Constructor Created

**AREA**
X: N/A
Amoeba: N/A
C1: 78.54
C2: 314.16
R: 32.00

**INFO**
(0,0)
Id: 0
(3,4)
Id: 1
(3,4)
Id: 2
Radius: 5, Area: 78.54
(15,20)
Id: 3
Radius: 10, Area: 314.16
(12,5)
Id: 4
Lenght: 8, Width: 4, Area: 32.00

**DISTANCES**
Shape copied
Shape copied
The distance between the two shapes is: 20.00
Shape destructed
Shape destructed
Distance from Origin for C1: 4.24
Distance from Origin for C2: 21.21
Distance from Origin for R: 16.97

**TOTAL SHAPES**
Shape copied
The total number of shapes are: 5
Shape destructed

Rectangle destructed
Shape destructed
Circle destructed
Shape destructed
Circle destructed
Shape destructed
Shape destructed
Shape destructed

//ok
************************/
