#ifndef DEMANDGENERATOR_H
#define DEMANDGENERATOR_H

#include <iostream>
#include <string>
#include <fstream>
#include "Constant.h"

using namespace std;



/**
 * @class DemandGenerator
 * @brief Generates random vehicle charging demands and writes them to a file.
 * 
 * The DemandGenerator class is responsible for creating a set of random charging demands
 * for vehicles. It generates random vehicle IDs, destination IDs, capacity ranges, and 
 * remaining ranges, ensuring that each generated demand meets specific criteria. The 
 * generated demands are then written to an output file for further processing.
 */
class DemandGenerator{

    public: 

        void generateDemands();


};

void DemandGenerator::generateDemands(){
     srand(time(0));

    ofstream outFile;

    outFile.open("RandomDemands.txt");

    int numOfDemands = MIN_DEMANDS + rand() % (MAX_DEMANDS - MIN_DEMANDS + 1);

    for(int i = 0; i < numOfDemands; i++){
        int vehicleId, destinationId, capasityRange, remainRange;


        vehicleId = 200 + i;
        destinationId = (rand() % 12) + 1;
        while(destinationId > 11)
        {
            destinationId = (rand() % 12) + 1;
        }
        int distance = distanceMap[destinationId - 1];
        capasityRange = MIN_CAPACITY + rand() % (MAX_CAPACITY - MIN_CAPACITY + 1);
        if((capasityRange - distance) < MIN_REMAIN_RANGE)
        {
            capasityRange = MIN_CAPACITY + rand() % (MAX_CAPACITY - MIN_CAPACITY + 1);
        }
        remainRange = capasityRange - distance;



        outFile << "[" << vehicleId << ',' << destinationId << ',' << capasityRange << ',' << remainRange << "]\n";

    }

    outFile.close();
}


#endif