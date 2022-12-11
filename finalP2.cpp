#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;


int main (){
   string Name = "Fahad Faruqi";
    cout << "-----------------------------------------\n";
    cout << "Name: " << Name << endl;
    cout << "FILE: " << __FILE__ << "\tDATE: " << __DATE__ << endl;
    cout << "-----------------------------------------\n";

    ifstream in("sunHem.txt"); //opens txt file

    if(!in){return 1;} //incase of error -> break

    set<string> novel;
    string words;

    while(getline(in, words, ' ')){ // takes in each word that it reads and stores in in the set
        novel.insert(words);
    }
    in.close(); // just in case

    printf("The total number of unique words in this set are:  %i\n", novel.size()); // size of set == unique elements
    cout << "******************************************************\n";


    int hist[20]; //histogram
    for (int i(0); i<20; i++){hist[i]=0;} // set all to 0
    
    //calculate # of lenghts of words
    for (const string& word : novel) { //  goes through each word in the set
        hist[word.length()]++; // increment the value of each word's lenght by 1
    }

    //print "histogram"
    for (int i(0); i < sizeof(hist)/sizeof(hist[0]); i++){
        printf("Number of Words of Size %i: %i\n", i, hist[i]); 
    }

    int upperCase = 0;
    for (const string& word : novel) {
    // Check if the first character of the word is an upper-case letter
        if (word[0] > 64 && word[0] < 92) {
        upperCase++;
        }
    }
    cout << "******************************\nNumber of words that start with an upper-case letter: " << upperCase << endl; // print results
    return 0;
}