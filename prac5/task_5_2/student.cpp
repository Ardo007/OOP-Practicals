#include <iostream>
#include "student.h"

using namespace std;

int main(){
    string name;
    int unitNum;

    cout << "Enter Student's name: ";
    getline(cin >> ws, name);

    cout << "Enter number of units: ";
    cin >> unitNum;

    while(unitNum < 0){
        cout << "Invalid number of units. Please enter a positive number: ";
        cin >> unitNum;
    }

    Student student(name, unitNum);
    student.start();

    return 0;
}