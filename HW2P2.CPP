#include <iostream>
using namespace std;

/*
Write a function that takes as argument an array of integers and the size of the array and 
returns the average of the input values.
    - Int = avrg(int * array, int size)**
*/

int avrg(int *&Array, int size){ //had to pass it in as reference
    int average(0);
    
    for (int i =0; i < size; i++){ //forloop adds together all elements of array
        average+= Array[i];
    }

    return average/size;
};

int main() {
    
    string name = "Fahad Faruqi";
    cout << endl << "===========================================================\n";
    cout << " " << name << "\t File: " << __FILE__ << "\t Date: " << __DATE__<< endl;
    cout << "===========================================================\n" << endl;
    
    int size = 5;
    int *pntr = new int[size]; //pointer array
    
    for (int i =0; i <size; i++){ // gives pointer array values
        pntr[i] = i;
    }

    cout << "Average of array is: " << avrg(pntr, size);
    }