#include <iostream>
using namespace std;

struct node{
	string Fruit;		//name
	int cnt;		//#fruits

    public:
    node (){
        cnt = 0;
    }
}; 



int main () {
    string name = "Fahad Faruqi";
    cout << "--------------------------------------------------------------------------\n";;
    cout << "Name: " << name << endl;
    cout << "FILE: " << __FILE__ << "\tDATE: " << __DATE__ << endl;
    cout << "--------------------------------------------------------------------------\n";


    node fruits[21];
    string fruitName[21] = {"Apple", "Banana", "Cherry", "Date", "Elden Ring", "Fig", "Guava", "Honeydew", "Jackfruit", "Kiwi", "Lemon", "Mango", "Nut", "Orange", "Pear",
    "Quince" "Raisin", "Strawberry", "Tangerine", "Watermelon", "Yumberry"};

    for (int i = 0; i<21; i++){ // initalize fruits
        fruits[i].cnt = i+1;
        fruits[i].Fruit = fruitName[i];
    }

    node*hashArray[11];
    for (int i = 0; i < 11; i++){
        hashArray[i]  = new node[10];
    }


    return 0;
}