//Points off:  -0.25
/************
HW2P1.CPP:/Points off:  -0.25
HW2P2.CPP://Points off: 0
Grade:  9.75/10
************/

#include <iostream>
using namespace std;
/*
Write a program having a String class that contains a function that can reverse the order 
of the characters in a string. A palindrome is a word or group of words that read the same
forward and backward. For example “madam” or “wow”. Write a program that takes a string argument 
from the command line and returns TRUE if the string is a palindrome.
*/
class String{
    
    private:   
    string reverse(string &word){
        string reversed; //empty string
        
        for (int i =0; i < word.size(); i++){
            reversed += word[word.size()-i-1];
        }
        return reversed;
    } //this function works
    
    bool palindrome(string word, string reversed){
        if (reversed == word){ //checks if the words are the same
            return true;
        }
        return false;
    } //this works too

    public:
    string word;
    bool isPalindrome = palindrome(word, reverse(word));	//syntax error
};


int main () {
    string name = "Fahad Faruqi";
    cout << endl << "===========================================================\n";
    cout << " " << name << "\t File: " << __FILE__ << "\t Date: " << __DATE__<< endl;
    cout << "===========================================================\n" << endl;

    
    String palindrome;
    cout << "Input a palindrome: ";
    cin >> palindrome.word;
    
    if (palindrome.isPalindrome){
        cout << "It's a palindrome!\n";
    } else{
        cout << "It's not a palindrome\n";
    }
    cout << endl;
}
/*****************
HW2P1.CPP:30:23: warning: in-class initialization of non-static data member is a C++11
      extension [-Wc++11-extensions]
    bool isPalindrome = palindrome(word, reverse(word));
                      ^
1 warning generated.						(-0.25)


******************/
