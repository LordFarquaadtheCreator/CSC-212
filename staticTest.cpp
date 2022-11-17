#include <iostream>
using namespace std;



int main(){
    int array[2];
    for(int i = 0; i < 2; i++){
        array[i] = i;
    }
    cout << array[0] << array[1];
}