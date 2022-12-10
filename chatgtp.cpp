#include <array>
#include <iostream>
#include <string>
using namespace std;

// Define the Node struct
struct Node {
  string Fruit;  // Name
  int cnt;            // # fruits
};

// Define the HashArray class
class HashArray {
private:
  // Define an array of Node* pointers
  array<Node*, 11> arr;

public:
  // Constructor that initializes the array elements to nullptr
  HashArray() {
    for (int i = 0; i < arr.size(); i++) {
      arr[i] = nullptr;
    }
  }

  // Method to calculate the key (index) for a given fruit name
  int HashFunction(string fruit) {
    // Calculate the sum of the ASCII values of each character in the fruit name
    int sum = 0;
    for (char c : fruit) {
      sum += c;
    }

    // Return the sum modulo the size of the HashArray
    return sum % arr.size();
  }

  // Method to insert a fruit and its count into the HashArray
  void Insert(Node* fruit) {
    // Calculate the key (index) for the fruit using the HashFunction
    int key = HashFunction(fruit->Fruit);

    // Check if the key (index) is already occupied
    if (arr[key] == nullptr) {
      // If the key (index) is not occupied, store the fruit at that index
      arr[key] = fruit;
    } else {
      // If the key (index) is already occupied, find the next free index
      int i = key + 1;
      while (arr[i] != nullptr && i != key) {
        i = (i + 1) % arr.size();
      }

      // If a free index was found, store the fruit at that index
      if (i != key) {
        arr[i] = fruit;
      }
    }
  }
};

