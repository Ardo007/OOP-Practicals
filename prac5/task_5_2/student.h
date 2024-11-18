#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
using namespace std;


class Student {
    private:
        string name;
        int numUnits;
        string *unitList;
    public:
        Student(string name1, int numUnit){
            unitList = new string[numUnit];
            numUnits = numUnit;
            name = name1;
        }
        ~Student(){
            delete[] unitList;
        }
        void addUnit(string unitList[]);
        void displayStudent(string& name, string numUnit[]);
        void start();

};


void Student::addUnit(string unitList[]){
    for(int i = 1; i <= numUnits; i++){
        cout << "Enter name of Unit  " << i << ": ";
        getline(cin >> ws, unitList[i - 1]);
    }
}


void  Student::displayStudent(string& name, string unitList[]){
    cout << "Student Name: " << name << endl;
    cout << "Units enrolled: ";
    for(int i = 1; i <= numUnits; i++){
        cout << unitList[i -1] << " ";
    }
}

void Student::start(){
    addUnit(unitList);
    displayStudent(name, unitList);
}



#endif