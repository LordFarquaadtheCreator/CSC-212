/*
Write a program that creates a stack container from a Singly Linked List. 
Demonstrte using it by creating a stack of 9 car models.
*/
#include <iostream>
using namespace std;

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

int main (){ 
    string name = "Fahad Faruqi";
    cout << endl << "==================================================================================\n";
    cout << " " << name << "\t File: " << __FILE__ << "\t Date: " << __DATE__<< "\tCSC 21200 LM24126" << endl;
    cout << "==================================================================================\n" << endl;

    string model;
    for(int i = 0; i <9; i++){ //only 9 car models allowed
        cout << "Car Model: ";
        cin >> model;
        push(model);
    }

    print();
}
