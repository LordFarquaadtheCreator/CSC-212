/*
Write a program that creates a stack container from a Singly Linked List. 
Demonstrte using it by creating a stack of 9 car models.
*/
#include <iostream>
using namespace std;

struct node{
    string model;
    node *next;
} *top = NULL;

void push(string model){
    node* newNode = new node;

    newNode->model = model;
    newNode->next = top;

    top = newNode;
}

void print(){
    node * temp = top;

    while (temp != NULL){
        cout << temp->model << endl;
        temp = temp->next;
    }
} 

int main (){ // this was much harder than i thought it would be
// this is like my linked list in part 1 but reversed
    string model;
    node *head; 
    for(int i = 0; i <9; i++){
        cout << "Car Model: ";
        cin >> model;
        push(model);
    }

    print();
}
