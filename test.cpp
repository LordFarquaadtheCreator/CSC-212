#include <iostream>
using namespace std;

template <class T>
class foo {
public:
    T foo2furious(){
        return 2-5;
    }
};

int main() {
    foo<int>obj1;
    obj1.foo2furious();
}