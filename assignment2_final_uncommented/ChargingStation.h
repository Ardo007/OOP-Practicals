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
        int queue;

    public: 
        ChargingStation(int station){
            cityId = station;
            cityName = nameMap[station];
            distanceToLastCity = distanceMap[station];
            numberOfChargers = chargersMap[station];
            queue = 0;
        }

        int getCityId();
        string getCityName();
        int getDistanceToLastCity();
        int getNumOfChargers();
        int getQueue();

        void increaseQueue();
        void setQueue();

        void printStation();
        int distanceToSydney();
        double AverageWaitTime();


    
};


void ChargingStation::printStation(){
    cout << setw(5) << cityId;
    cout << setw(20) << cityName;
    cout << setw(20) << distanceToLastCity;
    cout << setw(20) << numberOfChargers;
}


int ChargingStation::distanceToSydney(){
    int distance = 0;
    
    for(int i = 0; i <= this->cityId; i++){
        distance += distanceMap[i];
    }

    return distance;

}

double ChargingStation::AverageWaitTime(){
    return (0.5 * this->queue)/this->numberOfChargers;
}


void ChargingStation::increaseQueue(){
    this->queue++;
}

int ChargingStation::getQueue(){
    return queue;
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


void ChargingStation::setQueue(){
    this->queue = 0;
}


#endif