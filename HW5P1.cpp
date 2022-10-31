#include <iostream>
using namespace std;

/*
1. Write a program that creates a singly link list of used automobiles containing nodes that describe the model name (string), 
price(int) and owner’s name. The program should create a list containing 12 nodes created by the user. There are only three 
types of models (BMW, Cadillac, Toyota) and the prices range from $7500 – $20,500. The program should allow the user to provide
- **Print a printout of all cars contained in the list (model, price, owner) – Print(list_ptr*)**
- **Provide a histogram(global array) of all cars in the list portioned into $500 buckets** 
- **Find all cars that cost less $7500 - find_if( list_ptr*, int )**
- **Calculate the average price of the cars contained in the list – avrg(list_ptr* )**
- **Provide the details for all cars more expensive than the average price**
- **Remove all nodes having a price less than 25% of average price – remove(list_ptr*, int average)**
- **Print a printout of all cars contained in the updated list (model, price, owner)**
    1. **Write a program that creates a stack container from a Singly Linked List. Demonstrte using it by creating a stack 
    of 9 car models.**
*/

struct node{
    string modelName;
    float price;
    string ownerName;

    node* next;
};

void printList(node *head){
    node *temp; // this node will be the one that "moves" across the list
    temp = head; // temp will now point to the head to begin with
    int i=1;

    while (temp->next !=NULL){
        printf("Car %i Model: %s\t Price: %.2f\tOwner: %s\n", i, temp->modelName.c_str(), temp->price, temp->ownerName.c_str());
        i++;
        temp = temp->next; // temp now points to the next node
    }
}

void find_if(node *head, int price){ // same sorting logic as printList
    node *temp;
    temp = head;

    for (int i =1; i< 13; i++){
        if(temp->price < price){
            printf("The %s ($%f) is below $%i\n", temp->modelName.c_str(), temp->price, price);
        }
        
        temp = temp->next;
    }
}

float averagePrice(node *head){
    node *temp;
    temp = head;
    float sum = 0;

    while(temp->next != NULL){
        sum = sum+ temp->price;
        temp = temp->next;
    }
    return  sum/12;
}

void  moreThanAverage(node* head){
    node *temp;
    temp = head;
    double average = averagePrice(head);

    for (int i =0; i< 12; i++){
        if(average < temp->price){
            printf("The %s is costiler than the average car price ($%.2f)\n", temp->modelName.c_str(), average);
        }
        temp = temp->next;
    }
}

void removeLow(node* head, float average){
    //remove all nodes less that 25% of average
    //logic: find the node -> unlink the node from it's next node -> unlink previous node from this node 
    //-> link previous node to the node ahead of it
    node* temp; 
    node* temp2 = NULL;
    temp = head; // we start from the head

    // one node needs to be behind the node we're looking at at all times
    while(temp->next != NULL){ 
        if (head->price < (.25*average)){
            temp = temp->next;
            head->next= NULL;
            head = temp;
            temp2 = temp;
        }
        else if (temp->price < (.25*average)){ // finds bad node
            temp2->next=temp->next; // the previous node skips the next node
            temp->next = NULL; // unlinks "bad" node from list -- now its all alone
            temp = temp2->next; // temp moves up in the list, temp2 stays behind
        }
        else{// if not, we move along like normal
            temp2 = temp;
            temp = temp->next;
        }
    }
    printList(head);
};

void histogram(node *head){
    // **Provide a histogram(global array) of all cars in the list portioned into $500 buckets** 
    //26 "buckets"
    //first - we take all the prices and sort them into $500 buckets


    int buckets[27]; // buckets == 0
    for (int i =0; i<27; i++){
        buckets[i]=0;
    }

    node *temp;
    temp = head; 
    int i =0;

    for (int i =0; i<27; i++){ // go through  buckets

        for (int j= 0; j < 12; j++){ // check prices
            
            if((temp->price <= 7500+(i*500)) && (temp->price > (7500+(500*(i-1))))){
                buckets[i]++;
                break;
            }
            temp = temp->next;
        }
    }
    
    cout<< "\n**Histogram**\n";

    // second- take the  buckets and print a histogram
    for (int i =0; i < 27; i++){

        printf("%i: ", 7500+(i*500));
        
        for (int j =0; j< buckets[i]; j++){
            cout << " x ";
        }
        cout << endl;
    }
}
int main(){
node* temp = NULL;
    node *head = new node;
    temp = head;

    for(int i =1; i < 13; i++){
        // printf("Input Car %i Model\n",i);
        // cin >> temp->modelName;
        printf("Input Car %i Price\n",i);
        cin >> temp->price;
        // printf( "Input Car %i Owner\n", i);
        // cin >> temp->ownerName;

        temp->next = new node;
        temp = temp->next;
    }
    // printList(head);
    // cout << "***********************************************\n";
    // printf("The average price is: $%.2f\n", averagePrice(head));
    // cout << "***********************************************\n";
    // find_if(head, 7500);
    // cout << "***********************************************\n";
    // moreThanAverage(head);
    // cout << "***********************************************\n";
    // removeLow(head, averagePrice(head));
    // cout << "***********************************************\n";
    histogram(head);

    return 0;
}