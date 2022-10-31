#include <iostream>
#include <string>
using namespace std;

/*
1. Write a short program that reads phrases from the input stream and stores each new line into an array of C++ strings.
 For each new line, the program computes the numeric sum value of each phrase terminated with ‘\n’.  ???
 For the following section of the Gettysburg Address store the numeric values of each phrase into a int cnt[32] array.

“Four score and seven years ago our fathers brought forth upon this continent, a new nation, conceived in Liberty, 
and dedicated to the proposition that all men are created equal.
Now we are engaged in a great civil war, testing whether that nation, or any nation so conceived and so dedicated, 
can long endure.
We are met on a great battle-field of that war. We have come to dedicate a portion of that field, as a final resting 
place for those who here gave their lives that that nation might live.
It is altogether fitting and proper that we should do this. .”
*/


int main () {

    string name = "Fahad Faruqi";
    cout << endl << "==================================================================================\n";
    cout << " " << name << "\t File: " << __FILE__ << "\t Date: " << __DATE__<< "\tCSC 21200 LM24126" << endl;
    cout << "==================================================================================\n" << endl;


    string strings[32]; // where we store strings
    int cnt[32]; //where we store the  size of each string
    string sentence; // what we store the input in
    int i =0;

    cout << "Please type in the Gettysburg Address:\n";
    while (getline(cin, sentence)){ // constantly takes in lines
        if (sentence == "break"){break;} //breaks when you type "break"

        strings[i] = sentence;
        cnt[i] = sentence.size();
        i++; 
    };
    cout << endl << "Results:\n";
    int totalChar=0;

    for (int i = 0; i < 32; i++){
        if (strings[i].size() > 0){
            printf("Line %i: %s\nString Size: %i\n", i+1, strings[i].c_str(), cnt[i]);
            totalChar += cnt[i];
        }
    }
    
    cout << endl << "Total chars: " << totalChar << endl;

    return 0;
}