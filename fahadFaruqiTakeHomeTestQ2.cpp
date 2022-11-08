#include <iostream>
#include <cmath> //needed to make life easier
using namespace std;


enum Color {R,O,Y,G,B,I,V}; // global declaration

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

		id = Cnt;
		Cnt ++;
    }
	Shape (int x, int y, Color X){
		cout << "Parameterized shape constructed\n";
		this->x = x;
		this->y= y;
		this->X=X;

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
		printf("(%i,%i)\nId: %i\n", x, y, id); //x and y coordiantes
	}

	friend class Circle;
	friend class Rectangle;
	friend void distance(Shape x, Shape y);
	friend void printTotalShapes(Shape x);
};

class Circle : public Shape {
	int radius;

	public:
	Circle(){
		radius =0;
		cout << "Circle Constructor Created\n";
	}
	Circle(int x, int y, Color X, int radius){
		this->x = x;
		this->y= y;
		this->X=X;
		this->radius = radius;
		cout << "Circle Parametrized Constructor Created\n";
	}
	~Circle(){
		cout << "Circle destructed\n";
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
		return (pow(radius,2)*3.141594);
	}

	void print(){
		printf("(%i,%i)\nId: %i\n", x, y, id); //x and y coordiantes
		printf("Radius: %i, Area: %.2f\n", radius, CalcArea());
	}
};

class Rectangle : public Shape {
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