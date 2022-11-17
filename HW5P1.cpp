#include <iostream>
using namespace std;

/*
---------SPECS---------
- singly linked list
    - contains model name (string)
    - price (int)
    - owners name (string)
- 12 nodes 
- three types of models allowed (BMW, Cadillac, Toyota)
- price range (7500-20500)
- print the list one more time for updated list

Functions:
- print(list_prt*)  ^u^
- histogram(global array) ^u^ dunno what im supposed to do with global array :/
- findLessThan7500(list_ptr*)
- avrg(list_prt*) average price ^u^
- greaterThanAverage(list_ptr*) ^u^
    provide details for all cars greater than average price
- removeLessThan25(list_ptr*, int average) ^u^
    Remove all nodes having a price less than 25% of average price
*/

struct node{
    string modelName;
    float price;
    string ownerName;
//could use constructors to overload << to print each node's specs
    node* next; // now the lists be getting linked

    node(){ // default
        modelName = "BMW";
        price = 0;
        ownerName = "Bob";
    }
};

void print(node *head){
    node *temp; // this node will be the one that "moves" across the list
    temp = head; // temp will now point to the head to begin with
    int i=1;

    while (temp->next !=NULL){
        printf("Car %i Model: %s\t Price: %.2f\tOwner: %s\n", i, temp->modelName.c_str(), temp->price, temp->ownerName.c_str());
        i++;
        temp = temp->next; // temp now points to the next node
    }
}

void histogram(node *head){
    // **Provide a histogram(global array) of all cars in the list portioned into $500 buckets** 
    //26 "buckets"
    //first - we take all the prices and sort them into $500 buckets
    int buckets[27]; // buckets == 0
    for (int i =0; i<27; i++){
        buckets[i]=0;
    }

    node *temp;
    int i =0;

    for (int i =0; i<27; i++){ // go through  buckets
        temp = head; 

        while(temp->next != NULL){ // check prices
            if((temp->price <= 7500+(i*500)) && (temp->price > (7500+(500*(i-1))))){
                buckets[i]++;
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

void findLessThan7500(node *head){
    node *temp;
    temp = head;

    while (temp->next != NULL){
        if(temp->price < 7500){
            printf("The $%.2f %s is below $7,500\n", temp->price, temp->modelName.c_str());
        }
        temp = temp->next;
    }
}

float avrg(node *head){
    node *temp;
    temp = head;
    float sum = 0;

    while(temp->next != NULL){
        sum = sum+ temp->price;
        temp = temp->next;
    }
    return  sum/12;
}

void  greaterThanAverage(node* head, float average){
    node *temp;
    temp = head;

    for (int i =0; i< 12; i++){
        if(average < temp->price){ //condition
            printf("The %s is costiler than the average car price ($%.2f)\n", temp->modelName.c_str(), average);
        }
        temp = temp->next;
    }
}

void removeLessThan25(node *head, float average){ // same sorting logic as print()
    node *temp;
    node *secTemp = NULL;
    temp = head;

    for (int i =1; i< 13; i++){
        if(temp->price < .25 *average){ // checks our condition
            printf("The %s ($%.2f) is below 25 percent of the average car price!\n", temp->modelName.c_str(), (temp->price*.25));

            //delete protocol
                // head protocol
                if (head->price < (.25*average)){ // we don't have to worry about secTemp here
                    head = head->next;
                    temp = head;
                }
                // body protocol
                else{
                    secTemp->next = temp->next; // secTemp is behind temp, now linked to the node ahead of temp
                }
                
        }
        secTemp = temp; // will always be behind temp
        temp = temp->next;
    }
    cout << "All car entries lower than 25% of the average have been deleted!\n";
}


int main(){
node* temp = NULL;
    node *head = new node;
    temp = head;

    for(int i =1; i < 13; i++){
        printf("Input Car %i Model\n",i);
        cin >> temp->modelName;
        printf("Input Car %i Price\n",i);
        cin >> temp->price;
        printf( "Input Car %i Owner\n", i);
        cin >> temp->ownerName;

        temp->next = new node;
        temp = temp->next;
    }
    print(head);
    cout << "***********************************************\n";
    printf("The average price is: $%.2f\n", avrg(head));
    cout << "***********************************************\n";
    findLessThan7500(head);
    cout << "***********************************************\n";
    greaterThanAverage(head, avrg(head));
    cout << "***********************************************\n";
    removeLessThan25(head, avrg(head));
    cout << "***********************************************\n";
    print(head);
    cout << "***********************************************\n";
    histogram(head);

    return 0;
}