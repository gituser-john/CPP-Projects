#include<iostream>
using namespace std;
class Counter {
    static int count;  // Static data member
public:
    Counter() { count++; }
    static int getCount() { return count; }
};
int Counter::count = 0;  // Definition outside class

int main() {
    Counter c1, c2;
    cout << Counter::getCount();  // Output: 2
}
