#ifndef CHARGINGSTATION_H
#define CHARGINGSTATION_H
#include <iostream>
#include <string>
#include "Constant.h"
#include "iomanip"
using namespace std;



/**
 * @class ChargingStation
 * @brief Represents a charging station located in a specific city.
 * 
 * The ChargingStation class encapsulates the properties and behaviors of a charging
 * station, including its location, distance to the previous city, number of chargers,
 * and the current queue of vehicles waiting to charge. It provides methods to access
 * and modify these properties, calculate distances, and determine average waiting times.
 */
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

        // Getter methods to access private member variables
        int getCityId();
        string getCityName();
        int getDistanceToLastCity();
        int getNumOfChargers();
        int getQueue();

        // Setter and modifier methods
        void increaseQueue();
        void setQueue();

        // Utility methods
        void printStation();
        int distanceToSydney();
        double AverageWaitTime();


    
};

/**
 * @brief Prints the charging station's details in a formatted output.
 */
void ChargingStation::printStation(){
    cout << setw(5) << cityId;
    cout << setw(20) << cityName;
    cout << setw(20) << distanceToLastCity;
    cout << setw(20) << numberOfChargers;
}


/**
 * @brief Calculates the total distance from this charging station to Sydney.
 * 
 * This method sums up the distances from this station back to Sydney by iterating
 * through the distanceMap up to the current city ID.
 * 
 * @return int The total distance to Sydney.
 */
int ChargingStation::distanceToSydney(){
    int distance = 0;
    // Sum distances from city 0 up to the current city ID
    for(int i = 0; i <= this->cityId; i++){
        distance += distanceMap[i];
    }

    return distance;

}

/**
 * @brief Calculates the average waiting time at the charging station.
 * 
 * The average waiting time is computed based on the current queue length and the
 * number of chargers available. while assuming that each vehicle takes 0.5 hours to charge.
 * 
 * @return double The average waiting time in hours.
 */
double ChargingStation::AverageWaitTime(){
    return (0.5 * this->queue)/this->numberOfChargers;
}


/**
 * @brief Increments the queue length by one.
 */
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


/**
 * @brief Resets the queue length to zero.
 * 
 */
void ChargingStation::setQueue(){
    this->queue = 0;
}


#endif