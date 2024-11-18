#include <iostream>
using namespace std;

void sort(int& a, int& b, int& c);

int main(){

    int a = 30;
    int b = 10;
    int c = 20;

    sort(a, b, c);

    cout << "the sorted numbers are a = " << a << " b = " << b << " c = " << c << '\n';

    return 0;
}

void sort(int& a, int& b, int& c){
    if (a > c){
        int temp = a;
        a = c;
        c = temp;
    }

    if (a > b){
        int temp = a;
        a = b;
        b = temp;
    }

    if(b > c){
        int temp = b;
        c = b;
        b = temp;
    }
}

// void swap(int a, int b)
// {
//     int temp = b;
//     b = a;
//     a = temp;
// }
