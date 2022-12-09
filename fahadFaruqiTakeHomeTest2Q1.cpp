#include <iostream>
using namespace std;
 
// Taking size of stack as 5
#define SIZE 5
 
template<class T> 
class Stack {
    // Taking data member top
    int top;
    // Initialising stack(array) of given size
    T stack[SIZE]; // size 5 declared globally

    public:
    Stack(){top = -1;}

    void push(T k);

    T pop();

    int topElement();

    bool isFull();

    bool isEmpty();
};

template <class T>
int Stack<T>::topElement(){
    // Initialising a variable to store top element
    int top_element = stack[top];
 
    // Returning the top element
    return top_element;
}

template <class T>
bool Stack<T>::isEmpty(){ // valid
    // Till top in inside the stack
    if (top == -1){return 1;}
    else{return 0;}
}

template <class T>
bool Stack<T>::isFull(){
    // Till top in inside the stack
    if (top == (SIZE - 1)){return 1;}
    else{return 0;}
}

template <class T>
void Stack<T>::push(T k){ //valid
    // Checking whether stack is completely filled
    if (isFull()) {
        // Display message when no elements can be pushed
        // into it
        cout << "Stack is full\n";
    }else{
    // Inserted element
    cout << "Inserted element " << k << endl;
    // Incrementing the top by unity as element
    // is to be inserted
    top++;
    // Now, adding element to stack
    stack[top] = k;
    }
}

template <class T>
T Stack<T>::pop(){ // valid
    // Initialising a variable to store popped element
    T popped_element = stack[top];

    // Decreasing the top as
    // element is getting out from the stack
    top--;

    // Returning the element/s that is/are popped
    return popped_element;
}

void Foo(Stack<int> &X){
    cout << "Enter Value" << endl;
    int temp;
    cin >> temp;
    X.push(temp);
}			


int main(){
    string name = "Fahad Faruqi";
    cout << "--------------------------------------------------------------------------\n";;
    cout << "Name: " << name << endl;
    cout << "FILE: " << __FILE__ << "\tDATE: " << __DATE__ << endl;
    cout << "--------------------------------------------------------------------------\n";

    // Creating object of Stack class in main() method
    Stack<int> i_stack; 

    // Adding elements to integer stack object
    // Custom integer entries
    i_stack.push(2);
    i_stack.push(54);
    i_stack.push(255);
    // Now, removing element from integer stack
    cout << i_stack.pop() << " is removed from stack"
         << endl;
	 
    Foo(i_stack);
 
    // Print and display the top element in integer stack
    cout << "Top element is " << i_stack.topElement() << endl;
    return 0;
}