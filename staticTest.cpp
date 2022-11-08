#include <iostream>
using namespace std;

class Shape {
    int x, y;
    static int Cnt; // how many shapes exist
    int id; //  contains

    public:
    Shape (int x, int y){
        cout << "whaaaa";
        Cnt ++;
        cout << Cnt;
    }
};


int main(){

    Shape cow (5,5);
    return 0;
}