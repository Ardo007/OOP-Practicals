#include<iostream>
#include<ctime>
#include <fstream>
#include <cstdlib>
#include<vector>

#include "Date.h"

using namespace std;

int main() {

    ifstream fin;

    fin.open("date_in.txt");
    if (fin.fail()) {
        cout << "Input file opening failed.\n";
        exit(1);
    }

    ofstream fout;
    fout.open("date_out.txt"); 
    if (fout.fail()) {
        cout << "Output file opening failed.\n";
        exit(1);
    }

    char deliminator;
    int day = 0;
    int month = 0;
    int year = 0;

    while (fin >> day) {
        fin.get(deliminator);
        fin >> month;
        fin.get(deliminator);
        fin >> year;
        fin.get(deliminator);
        Date d(day, month, year);
        cout << d << endl;
        fout << d << endl;
    }

    fin.close();
    fout.close(); // Don't forget to close the output file
	
	return 0;
}
