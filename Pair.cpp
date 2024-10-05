#include<iostream>
using namespace std;

class Pair {
    const int *a, *b;
    public:
        Pair(int val1, int val2) : a((int*)val1),b((int*)val2){}    //LINE-1
        ~Pair(){ delete a; delete b; }    //LINE-2
        int getA(){ return *a; }    //LINE-3
        int getB(){ return *b; }    //LINE-4
};
int main(){
    int x, y;
    cin >> x >> y;
    Pair p(x, y);
    cout << "[" << p.getA() << ", " << p.getB() << "]";
    return 0;
}