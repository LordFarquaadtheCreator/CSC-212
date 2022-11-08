#include <iostream>
using namespace std;

int main(){
    for (int i = 0; i < 5; i++){
        static int pi = 5;
        pi ++;
        cout << pi << endl;
    }
}