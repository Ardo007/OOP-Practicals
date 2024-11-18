#ifndef PRODUCTION_H_
#define PRODUCTION_H_

#include <iostream>
using namespace std;


class productionGraph {
    private:
        int *production;
        int size;
    public:
        productionGraph(int size_of_array){
            production = new int[size_of_array];
            size = size_of_array;
        }
        ~productionGraph(){
            delete[] production;
        }
        void inputData(int production[]);
        void getTotal(int&);
        void graph(const int production[]);
        void printAsterisks(int);
        void printGraph();
};

void productionGraph::printGraph(){
    cout << "This program displays a graph showing\n" 
         << "production for each plant in company.\n";

    inputData(production);
    graph(production);
}

void productionGraph::inputData(int production[]){
    for(int i = 1; i <= size; i++){
        cout << endl << "Enter production data for plant number " << i << endl;
        getTotal(production[i - 1]);
    }
}

void productionGraph::getTotal(int& amount){
    cout << "Enter a positive integer of units by each department, ranging from 1-20\n";
    cin >> amount;
    while(amount < 0 || amount > 20){
        cout << "invalid, input again\n";
        cin >> amount;
    }
}


void productionGraph::graph(const int production[]){
    cout << "\nUnits produced int units:\n";
    for(int i = 1; i <= size; i++){
        cout << "Plant #" << i << " ";
        printAsterisks(production[i - 1]);
        cout << endl;
    }
}

void productionGraph::printAsterisks(int n){
    for(int count = 1; count <= n; count++){
        cout << "*";
    }
}



#endif