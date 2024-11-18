#include <iostream>
#include <string>
using namespace std;


void testDefaultArg(int day = 1, string month = "Jan", int year = 2023);

int main(){

    testDefaultArg();
    testDefaultArg(10);
    testDefaultArg(10, "Jul");
    testDefaultArg(10, "Jul", 2023);


    return 0;
}


void testDefaultArg(int day, string month, int year) {
    cout << "Today is " << day <<" " << month << " " << year << endl;
}