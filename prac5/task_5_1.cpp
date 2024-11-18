//Reads data and displays a bar graph showing productivity for each plant.
#include <iostream>

using namespace std;

const int NUMBER_OF_PLANTS = 4;

void inputData(int a[]);

void graph(const int a[]);

void getTotal(int&);
//Reads nonnegative integers from the keyboard

void printAsterisks(int n);
//Prints n asterisks to the screen.

int main()
{
    int* production = new int[NUMBER_OF_PLANTS];

    cout << "This program displays a graph showing\n"
         << "production for each plant in the company.\n";

    inputData(production);
    graph(production);

    delete[] production;

    return 0;
}

void inputData(int production[])
{
    for (int i = 1; i <= NUMBER_OF_PLANTS; i++)
    {
        cout << endl
             << "Enter production data for plant number "
             << i << endl;
        getTotal(production[i - 1]);
    }
}

void getTotal(int& amount)
{
    cout << "Enter a positive integer of units produced by each department, ranging from 1-20.\n" << endl;
    cin >> amount;
    while (amount < 0)
    {
    	    cout<<"input again" << endl;
        cin >> amount;
    }
}

void graph(const int production[])
{
    cout << "\nUnits produced in units:\n";
    for (int i = 1; i <= NUMBER_OF_PLANTS; i++)
    {
        cout << "Plant #" << i << " ";
        printAsterisks(production[i - 1]);
        cout << endl;
    }
}

void printAsterisks(int n)
{
    for (int count = 1; count <= n; count++)
        cout << "*";
}



