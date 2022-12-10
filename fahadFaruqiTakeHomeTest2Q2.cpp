#include <iostream>
#include <string>
using namespace std;

struct node{
	string Fruit;		//name
	int cnt;		//#fruits

    public:
    node (){
        cnt = 0;
    }
}; 


int hashFunction(string key){
    return stoi(key) %11;
}



int main () {
    string name = "Fahad Faruqi";
    cout << "--------------------------------------------------------------------------\n";;
    cout << "Name: " << name << endl;
    cout << "FILE: " << __FILE__ << "\tDATE: " << __DATE__ << endl;
    cout << "--------------------------------------------------------------------------\n";


    node fruits[21];
    string fruitName[21] = {"Apple", "Banana", "Cherry", "Date", "Elden Ring", "Fig", "Guava", "Honeydew", "Jackfruit", "Kiwi", "Lemon", "Mango", "Nut", "Orange", "Pear",
    "Quince" "Raisin", "Strawberry", "Tangerine", "Watermelon", "Yumberry"};

    node*hashArray[11];
    for (int i = 0; i < 11; i++){
        hashArray[i]  = new node[10]; // chaining?
    }

    for (int i = 0; i<21; i++){ // initalize fruits
        fruits[i].cnt = i+1;
        fruits[i].Fruit = fruitName[i]; // name set

        hashArray[hashFunction(fruits->Fruit)] = &fruits[i]; // after each fruit is initialized, the name gets turned into an index and the address of said fruit is stored at that index in the hashArray
        // i dont know if this works or not cause all im storing the memory addresses of the array bits i want in the index bits i want, but don't know if it's going to
    }

    

    


    return 0;
}