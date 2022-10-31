#include <iostream>
using namespace std;

/*
Write a program containing a base Animal class that can contains member functions that can output (i) ”I can eat”, 
(ii) “I can sleep” as well as a showData() member function that outputs the weight and age. A derived class Dog contains a 
function that displays “I am a dog” and can output the dog species’ name (e.g. “bulldog”). Both the base class and derived 
class must have appropriate constructors, destructors and assignment=() operators.
*/


class Animal {
    public: // contains member functions 
    void canEat(){
        cout << "I can eat\n";
    }
    void canSleep(){
        cout << "I can sleep\n";
    }

    Animal(){
        canEat();
        canSleep();
    } //default constructor
    ~Animal(){}
    
    int weight, age;
    
    void showData() {
        printf("\nAnimal Weight: %ilbs\nAnimal Age: %i yrs\n", weight, age);
    } // works
};

class Dog : public Animal{
    public:
    string species; 
    
    Dog(){
        cout << "I am a dog, woof\n";
    };
    ~Dog(){}

    Dog (string species){
        cout << "I am a dog, woof\n";

        this-> species = species;
        printf("The dog's species is: %s\n",species.c_str());
    }
};

int main() {

    string name = "Fahad Faruqi";
    cout << endl << "==================================================================================\n";
    cout << " " << name << "\t File: " << __FILE__ << "\t Date: " << __DATE__<< "\tCSC 21200 LM24126" << endl;
    cout << "==================================================================================\n" << endl;


    Dog dog("Bulldog");
    dog.weight = 163;
    dog.age = 2;

    printf("\n%s's data: ", dog.species.c_str());
    dog.showData();
}

