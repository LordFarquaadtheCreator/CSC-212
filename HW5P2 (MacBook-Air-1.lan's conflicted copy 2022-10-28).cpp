/*
Write a program that creates a stack container from a Singly Linked List. 
Demonstrte using it by creating a stack of 9 car models.
*/
#include <iostream>
using namespace std;

struct node{
    string model;
    node *next;
};

void print(node * head){
    node * temp = head;

    while (temp->next != NULL){
        cout << temp->model << endl;
        temp = temp->next;
    }
}

void removeNode(node* head){
    node * temp = head;
    node * secTemp = head;

    while (temp->next != NULL){
        temp = temp->next;

        if(temp->next == NULL){
            secTemp->next = NULL;
        }

        secTemp = secTemp->next;
    } // now temp is at the last node

    print(head);
}

int main (){ // this was much harder than i thought it would be
// this is like my linked list in part 1 but reversed
    node *head =NULL;
    node *temp;
    
    for (int i =0; i < 9; i++){        
        head = new node;
        head->next = temp;
        temp = head;

        printf("Car %i Model: ", i+1);
        cin >> head->model;
    }

    // our "print" function
    //print(head);

    removeNode(head); // removes "last" node

    print(head);
}
