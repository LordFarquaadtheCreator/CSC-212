#include <iostream>
#include <map>
#include <vector>
using namespace std;
//compile in c++11 for no warnings
/* DIRECTIONS:
    - stores 20 fruits in a map <string name, int length > container Fruit
    - Print the entire map displaying fruit name & word-length
    - Display all fruits having a word-length > 5
    - Calculate the numerical sum of each fruit’s name and store it in a vector<int> Sum
    - Print the entire vector Sum
    - Calculate the mean(Mean) value of vector Sum
    - Display all fruits having numerical values less than Mean
*/
int main () {
    string Name = "Fahad Faruqi";
    cout << "-----------------------------------------------------------------------------\n";
    cout << "Name: " << Name << endl;
    cout << "FILE: " << __FILE__ << " DATE: " << __DATE__ << endl;
    cout << "------------------------------------------------------------------------------\n";
    map <string, int> fruits; // map created
    fruits["pear"] = 4;
    fruits["banana"] = 6;
    fruits["apple"] = 5;
    fruits["fig"] = 3;
    fruits["date"] = 4;
    fruits["watermelon"] = 10;
    fruits["guava"] = 5;
    fruits["grape"] = 5;
    fruits["berry"] = 5;
    fruits["orange"] = 6;
    fruits["blueberry"] = 9;
    fruits["mimosa"] = 6;
    fruits["mango"] = 5;
    fruits["mandarin"] = 8;
    fruits["grapefruit"] = 10;
    fruits["lemon"] = 5;
    fruits["lime"] = 4;
    fruits["papaya"] = 6;
    fruits["peach"] = 5;
    fruits["eldenberry"] = 10;

    // Print map including name and lenght
    cout << "*** PRINT MAP ***\n";
    for (const auto& pair : fruits) { // pair represents each data type 
        printf("Name: %s\tLenght: %i\n", pair.first.c_str(), pair.second);
    }

    // display all fruit having len = 5
    cout << "\n*** FRUITS WITH LEN > 5 ***:\n";
    for (const auto& pair : fruits) {
        if (pair.second > 5) { // less than and equal to 5 will be ignored
            printf("Fruit with Word Lenght > 5: %s\n", pair.first.c_str());
        }
    }

    // Calculate the numerical sum of each fruit’s name and store it in a vector<int> Sum
    vector<int> Sum;
    int sum = 0; 
    for (const auto& pair : fruits) {
        sum = 0; // reset sum to 0 for each new name
        for (char c : pair.first) { // goes through each char in a name 
            sum += c; // adds char to sum for name 
        }
        Sum.push_back(sum); // sum of all char values added to vector
    }

    // print Sum
    cout << "\n*** NUMERICAL SUMS OF FRUIT NAMES ***\n";
    for (int i = 0; i < Sum.size(); i++) { //for loop goes through each element in vector
        printf("Sum of Map Value %i: %i \n", i+1, Sum[i]); // print each element in vector
    }
    cout << endl;

    // Calculate the mean value of vector Sum
    int total = 0;
    for (int i = 0; i < Sum.size(); i++) {
        total += Sum[i]; // total sum calculated
    }

    int mean = total / Sum.size(); // mean calculated
    cout << "* MEAN == " << mean << " *\n";

    // Display all fruits with numerical values < mean
    cout << "\n*** FRUITS WITH NUMERICAL VALUES < MEAN ***\n";
    for (const auto& pair : fruits) {
        int sum = 0;

        // i cant use my vector Sum cause this for loop only goes through the values of the map with no 'i'
        for (char c : pair.first) { // go through each char like before
            sum += c; // recalculate sum :(
        }
        if (sum < mean) { // condition
            cout << pair.first << '\n';
        }
    }

    return 0;
}