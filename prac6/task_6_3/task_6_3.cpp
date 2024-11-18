#include <iostream>
#include "Constant.h"
#include <fstream>
#include <string>
#include <iomanip>
#include <random>


using namespace std;

int main (){

    srand(time(0));


    ofstream outFile;

    outFile.open("ChargingDemands.txt");

    int numOfDemands = MIN_DEMANDS + rand() % (MAX_DEMANDS - MIN_DEMANDS + 1);

    for(int i = 0; i < numOfDemands; i++){
        int vehicleId, destinationId, capasityRange, remainRange;


        vehicleId = 200 + i;
        destinationId = (rand() % 12) + 1;
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
    

    return 0;
}