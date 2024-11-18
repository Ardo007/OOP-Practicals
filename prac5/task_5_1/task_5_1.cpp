#include <iostream>
#include "productionGraph.h"

using namespace std;

int main(){

    int size_of_array;

    cout << "Enter the number of plants you want: ";
    cin >> size_of_array;
    while(size_of_array < 0){
        cout << "you cant have negative numbers, try again\n";
        cin >> size_of_array;
    }

    productionGraph graph(size_of_array);
    graph.printGraph();



    return 0;
}