#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
using namespace std;
// compile in C++11 or 17
/*DIRECTIONS
    - Reads all the words in the “SunRises.txt” file and stores them in multimap<string, int ) Roman
    - Prints all the elements (string & size) of Roman
    - Finds the longest word in Roman and stores it in int WrdLongest
    - Creates a vector<int> Histogram(WrdLongest, 0)
    - Print the Histogram vector
    - Print all the words in Roman that are longer than 9 letters
*/
int main() {
    string Name = "Fahad Faruqi";
    cout << "-----------------------------------------------------------------------------\n";
    cout << "Name: " << Name << endl;
    cout << "FILE: " << __FILE__ << " DATE: " << __DATE__ << endl;
    cout << "------------------------------------------------------------------------------\n";
    // Read the words from the file and store them in the multimap
    multimap<string, int> Roman;
    ifstream file("SunRises.txt"); //open text file
    string word;
    int size = 0;

    while (getline(file, word, ' ')) { //takes in all strings seperated by spaces
        Roman.emplace(word, word.length()); // add values word and len to map
    }

    // Print all the elements of the Roman
    cout << "*** PRINT WORDS AND SIZES ***\n";
    for (const auto& pair : Roman) {
        printf("%s\tSize: %i\n", pair.first.c_str(), pair.second);
    }

    // Finding the longest word in the multimap
    int WrdLongest = 0;
    string longString;
    for (const auto& pair : Roman) {
        if (pair.second > WrdLongest) { // sorting
            WrdLongest = pair.second;
            longString = pair.first;
        }
    }
    printf("\n*** The largest string is '%s' at %i lenght! ***\n", longString.c_str(), WrdLongest);

    // Create the Histogram vector
    vector<int> histogram(WrdLongest, 0);

    // Fill the Histogram vector with the word counts
    for (const auto& pair : Roman) {
        histogram[pair.second]++; // increments the value of the histogram at the word lenght index
    }

    // Print the Histogram vector
    cout << "\n*** HISTOGRAM ***\n";
    for (int i = 1; i <= WrdLongest; ++i) { // we dont wanna include vectors with len 0 lol
        //histogram
        printf("Hist[%i]: ", i);
        for (int j = 0; j < histogram[i]; j++){
            cout << 'x';
        }
        cout << endl;
    }

    //printing all the words in the multimap with size > 9
    cout << "\n*** WORDS WITH SIZE > 9 ***";
    for (const auto& pair : Roman) {
        if (pair.second > 9) { //condition
            cout << pair.first << endl;
        }
    }

    return 0;
}
