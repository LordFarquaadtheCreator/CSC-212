#include <iostream>
using namespace std;

/*
1. Write a program that implements a binary tree having nodes that contain the following items: (i) Fruit name (ii) price per lb.  
The program should allow the user to input any fruit name (duplicates allowed), price.  The root node should be initialized to 
{“Lemon” , $3.00}.  The program should be able to do the following tasks:
    1. create a basket of 16 fruits/prices
    2. list all the fruits created (name/price)
    3. calculate the average price of the basket
    4. print out all fruits having the first letter of their name >= ‘L’

------SPECS------
Binary tree with:
    fruit name (string)
    price per lb (float)
Root Node = {"Lemon", $3.00}

------FNS-------
    Add any fruit name
    Add any price
    Create16 nodes
    Print()
    Avrg()
    printLetter(char c) ~ print any fruit with the first letter being c
*/

struct node{
    string model;
    node *next;
} *head = NULL;

void push(string model){ // pushes the data onto a new node that's added to the front
    node* newNode = new node;

    newNode->model = model;
    newNode->next = head; //the first node points to nothing

    head = newNode; // all subsequent nodes point "downward" to the first
}

void print(){
    node * temp = head; // by now all nodes should be declared and added, so this points to the top of it
    cout << "****CAR MODELS****\n";
    
    while (temp != NULL){
        cout << "Car Model:" << temp->model << endl;
        temp = temp->next;
    }
} 

int main(){
    return 0;
}