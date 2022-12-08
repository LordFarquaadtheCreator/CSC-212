#include <iostream>
using namespace std;

//Class for a pair of values of type T:
template<class T>
class Pair
{
public:
    Pair( );					//default constructor
    Pair(T firstValue, T secondValue);		//parametrized constructor
    //accessor & mutators
    void setFirst(T newValue);
    void setSecond(T newValue);
    T getFirst( )const{return first;}	
    T getSecond( )const{return second;}

    //Pair & operator=(const Pair &rhs);        //P1=P2
                                                //P1.operator=(P2);
    Pair<T> & operator=(const Pair<T> &rhs); //assignment operator
    //output operator -friend 
    template<class U>
    friend ostream & operator<<(ostream &os, const Pair<U> &rhs); 
private:
    T first;
    T second;
};

//member definitions
template<class T>
Pair<T>::Pair(T firstValue, T secondValue)      //Parametirized constructor
{
    first = firstValue;
    second = secondValue;
}
template<class T>
Pair<T>::Pair()
{
    first = 0;
    second = 0;
}

template<class T>
void Pair<T>::setFirst(T newValue)
{
    first = newValue;
}

template<class U>
ostream & operator<<(ostream &os, const Pair<U> &rhs){
	os << "first = " << rhs.first << " second = " << rhs.second;
	return os;
} 

template<class T>
Pair<T> & Pair<T>::operator=(const Pair<T> &rhs){
	if(this != &rhs)
        {
		first = rhs.first;
		second = rhs.second;
                return *this;
	}
	return *this;
}
	
		

int main( )
{
    Pair<char> P('A', 'B');
    Pair<char> R('F', 'G');
    Pair<char> Q;
    Pair<int>   I(25, 35);

    cout << "P:" << P << endl;
    cout << "R:" << R << endl;
    cout << "I: " << I << endl;

    cout << "First is " << P.getFirst( ) << endl;
    cout << "Second is " << P.getSecond( ) << endl;
    P.setFirst('Z');
    cout << "First changed to " << P.getFirst( ) << endl;
    Q = R;
    cout << "Q: " << Q << endl;
    return 0;
}
/**************************
./a.out
P:first = A second = B
R:first = F second = G
I: first = 25 second = 35
First is A
Second is B
First changed to Z
Q: first = F second = G

****************************/
