#include <iostream>
using namespace std;

/*
Two words are said to be anagrams if they contained the same characters but in different order – 
for instance “rescue” and “secure”. Write a program that takes two strings and determines if they are 
anagrams of each other (hint – sort both words and check if they match)
*/

int main(){

    string name = "Fahad Faruqi";
    cout << endl << "==================================================================================\n";
    cout << " " << name << "\t File: " << __FILE__ << "\t Date: " << __DATE__<< "\tCSC 21200 LM24126" << endl;
    cout << "==================================================================================\n" << endl;

    string one, two;
    cout << "First word: ";
    cin >> one;
    cout << "Second word: ";
    cin >> two;

    sort(two.begin(), two.end());
    sort(one.begin(), one.end());

    if (one == two){
        cout << "It's an anagram!";
    }
    else{
        cout << "Not an anagram";
    }
}