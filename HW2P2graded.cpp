//Points off: 0

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

    return average/size;			//ok
};

int main() {
    
    string name = "Fahad Faruqi";
    cout << endl << "===========================================================\n";
    cout << " " << name << "\t File: " << __FILE__ << "\t Date: " << __DATE__<< endl;
    cout << "===========================================================\n" << endl;
    
    //int size = 5;
    int size = 13;				//YS input
    int *pntr = new int[size]; //pointer array
    
    for (int i =0; i <size; i++){ // gives pointer array values
        pntr[i] = i;
    }

    cout << "Average of array is: " << avrg(pntr, size);
    }

/*************
./a.out

===========================================================
 Fahad Faruqi	 File: HW2P2.cpp	 Date: Sep 19 2022	//ok
===========================================================

Average of array is: 2

------------------
./a.out

===========================================================
 Fahad Faruqi	 File: HW2P2.cpp	 Date: Sep 19 2022
===========================================================

Average of array is: 6

//ok
***********************/
