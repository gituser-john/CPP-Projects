#include <iostream>
using namespace std;

int globalVar = 5;

class MyClass {
    int memberVar;
public:
    MyClass(int memberVar_ = 0) : memberVar(++memberVar_) { ++globalVar; } // LINE-1
    ~MyClass() { memberVar = 0; globalVar = 0; }
    void display() {
        cout << "memberVar = " << memberVar << ", globalVar = " << globalVar << endl;
    }
};

void function() {
    MyClass obj;
    obj.display();
}

int main() {
    MyClass obj;
    function();
    obj.display();
    return 0;
}
