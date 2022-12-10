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

    ifstream in("sunHem.txt");

    if(!in){
        cout << "Didn't Open Correctly :/\n";
        return 1;
    }

    set<string> novel;
    string words;

    while(getline(in, words, ' ')){ // takes in each word that it reads and stores in in the set
        novel.insert(words);
    }

    cout << "Words in the novel:\n ";
    for (const string& w : novel) {
        cout << w << "\n";
    }
    cout << endl;

    // something may be wrong, the online calculator is giving me 166 unique words 

    printf("The total number of unique words in this set are:  %i\n", novel.size()); // size of set == unique elements


    int hist[20];
    for (int i(0); i<20; i++){hist[i]=0;}

    for(const string& w: novel){
        hist[w.size()]++;
    }
    for (int i(0); i < sizeof(hist)/sizeof(hist[0]); i++){
        printf("Number of Words of Size %i: %i\n", i+1, hist[i]); // something is wrong
    }

}