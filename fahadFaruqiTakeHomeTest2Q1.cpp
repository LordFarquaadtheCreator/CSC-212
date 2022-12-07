#include <iostream>
#include <string>
using namespace std;
 
// Taking size of stack as 5
#define SIZE 5
 
class Stack {
public:
    // Empty constructor
    Stack();
 
    // Method 1
    // using stack push() operation
    void push(int k);
 
    // Method 2
    // To remove top element from stack
    int pop();

    // Method 3
    // To print top element in stack
    int topElement();
 
    // Method 4
    // To check whether stack is full
    bool isFull();
 
    // Method 5
    // To check whether stack is empty
    bool isEmpty();
 
private:
    // Taking data member top
    int top;
 
    // Initialising stack(array) of given size
    int st[SIZE];
};

// Method 6
// To initialise top to
// -1(default constructor)
Stack::Stack() { top = -1; }

// Method 7
// To add element element k to stack
void Stack::push(int k)
{
 
    // Checking whether stack is completely filled
    if (isFull()) {
        // Display message when no elements can be pushed
        // into it
        cout << "Stack is full\n";
    }
 
    // Inserted element
    cout << "Inserted element " << k << endl;
 
    // Incrementing the top by unity as element
    // is to be inserted
    top = top + 1;
 
    // Now, adding element to stack
    st[top] = k;
}

// Method 8
// To check if the stack is empty
bool Stack::isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
// Utility methods
// Method 9
// To check if the stack is full or not
bool Stack::isFull()
{
    // Till top in inside the stack
    if (top == (SIZE - 1))
        return 1;
    else
 
        // As top can not exceeds th size
        return 0;
}

// Method 10
int Stack::pop()
{
    // Initialising a variable to store popped element
    int popped_element = st[top];
 
    // Decreasing the top as
    // element is getting out from the stack
    top--;
 
    // Returning the element/s that is/are popped
    return popped_element;
}

// Method 11
int Stack::topElement()
{
    // Initialising a variable to store top element
    int top_element = st[top];
 
    // Returning the top element
    return top_element;
}
 
// Method 12
// Main driver method

   void Foo(Stack &X)
   {
        cout << "Enter Value" << endl;
        int temp;
        cin >> temp;
        X.push(temp);
}							//function prototype

int main()
{
    // Creating object of Stack class in main() method
    Stack i_stack;
 
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
    cout << "Top element is " << i_stack.topElement()
         << endl;
 
    return 0;
}