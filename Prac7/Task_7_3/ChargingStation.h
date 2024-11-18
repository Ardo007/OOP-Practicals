#ifndef CHARGINGSTATION_H
#define CHARGINGSTATION_H
#include <iostream>
#include <string>
#include "Constant.h"
#include "iomanip"
using namespace std;

class ChargingStation {
    private:
        int cityId;
        string cityName;
        int distanceToLastCity;
        int numberOfChargers;

    public: 
        ChargingStation(int station){
            cityId = station;
            cityName = nameMap[station];
            distanceToLastCity = distanceMap[station];
            numberOfChargers = chargersMap[station];
        }

        int getCityId();
        string getCityName();
        int getDistanceToLastCity();
        int getNumOfChargers();

        void printStation();
        int distanceToSydney(int city);
    
};


void ChargingStation::printStation(){
    cout << setw(5) << cityId;
    cout << setw(20) << cityName;
    cout << setw(20) << distanceToLastCity;
    cout << setw(20) << numberOfChargers;
}



int ChargingStation::distanceToSydney(int city){
    int distance = 0;
    for(int i = 0; i <=city; i++){
        distance += distanceMap[i];
    }

    return distance;

}



int ChargingStation::getCityId(){
    return cityId;
}

string ChargingStation::getCityName(){
    return cityName;
}

int ChargingStation::getDistanceToLastCity(){
    return distanceToLastCity;
}

int ChargingStation::getNumOfChargers(){
    return numberOfChargers;
}


#endif