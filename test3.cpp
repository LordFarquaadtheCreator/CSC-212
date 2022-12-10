#include <iostream>
#include <string>
using namespace std;

struct node{
	string Fruit;		//name
	int cnt;		//#fruits

    public:
    node (){
        cnt = 15;
    }
}; 

int hashFunction(string key){
    int sum(0);
    for (int i(0); i < key.size(); i++){ // adds up all char vals
        sum += int(key[i]);
    }
    // cout << key <<"\t" << sum%11 << endl; //debug
    return sum%11;
}

int main () {
    string name = "Fahad Faruqi";
    cout << "--------------------------------------------------------------------------\n";;
    cout << "Name: " << name << endl;
    cout << "FILE: " << __FILE__ << "\tDATE: " << __DATE__ << endl;
    cout << "--------------------------------------------------------------------------\n";

    node fruits[21];
    string fruitName[21] = {"Apple", "Banana", "Cherry", "Date", "Eldenberry", "Fig", "Guava", "Honeydew", "Jackfruit", "Kiwi", "Lemon", "Mango", "Nut", "Orange", "Pear",
    "Quince" "Raisin", "Strawberry", "Tangerine", "Watermelon", "Yumberry"};

    node *hashArray[11][10];
    int j = 0;

    for (int i = 0; i<21; i++){ // initalize fruits
        if (fruitName[i] == ""){ // just incase ...
            break;
        }
        fruits[i].cnt = i+1;
        fruits[i].Fruit = fruitName[i]; // name set

        // cout << i << endl;

        
        while(hashArray[hashFunction(fruits[i].Fruit)][j] == NULL){ // while loop checks that the index value and chain have space
            j++;
        }

        hashArray[hashFunction(fruits[i].Fruit)][j] = &fruits[i]; // after each fruit is initialized, the name gets turned into an index and the address of said fruit is stored at that index in the hashArray
        j=0; // reset
    }


    cout << "\n**** PRINTED HASHTABLE ****\n";
    for(int i(0); i<11; i++){ // goes through index
        for(int j(0); j<10; j++){ // goes through chain
            if (hashArray[i][j-1] == NULL){break;}
            else {
                if(hashArray[i][j] != NULL){
                printf("Fruit: %s\tCnt: %i\n", hashArray[i][j]->Fruit.c_str(), hashArray[i][j]->cnt);
                }
            }
            
            cout << i << j << endl;
        }
    }
    
    return 0;
}