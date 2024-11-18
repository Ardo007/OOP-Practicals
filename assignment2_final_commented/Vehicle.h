#ifndef VEHICLE_H_
#define VEHICLE_H_
#include <iostream>
#include <string>
#include <iomanip>
#include "Constant.h"
#include "ChargingStation.h"
using namespace std;



/**
 * @class Vehicle
 * @brief Represents an electric vehicle with specific attributes and behaviors.
 * 
 * The Vehicle class encapsulates the properties of an electric vehicle, including its ID,
 * current location, destination, range capacity, and remaining range. It provides methods
 * to access and modify these properties, as well as functionalities to print vehicle details
 * and calculate the furthest city it can travel to with the remaining range.
 */
class Vehicle
{
    private:
        int vehicleId;
        int currentCityId;
        int destinationId;
        int capacityRange;
        int remainRange;

    public:
        Vehicle(int VehicleId, int CurrentCityId, int DestinationId, int CapacityRange, int RemainRange)
        {
            vehicleId = VehicleId;
            currentCityId = CurrentCityId;
            destinationId = DestinationId;
            capacityRange = CapacityRange;
            remainRange = RemainRange;
        }

        int getVehicleId();
        int getCurrentCityId();
        int getDestinationId();
        int getCapacityRange();
        int getRemainRange();

        void setOrigin(int CurrentCityId);
        void setRemainRange(int RemainRange);

        void print();
        int furthestCityToTravelTo();
};



/**
 * @brief Prints the vehicle's details in a formatted output.
 * 
 */
void Vehicle::print()
{
    cout << setw(5) << vehicleId;
    cout << setw(20) << nameMap[currentCityId];
    cout << setw(20) << nameMap[destinationId];
    cout << setw(20) << capacityRange;
    cout << setw(20) << remainRange;
}



/**
 * @brief Calculates the furthest city the vehicle can travel to with its remaining range.
 * 
 * This method iterates through the cities from the current location towards the destination,
 * subtracting the distance between cities from the remaining range. It returns the distance
 * traveled until the vehicle can no longer reach the next city due to insufficient range.
 * 
 * @return int The total distance the vehicle can travel before running out of range.
 */
int Vehicle::furthestCityToTravelTo(){
    int distance = 0;       // Total distance traveled
    int range = this->remainRange;      // Copy of the remaining range

    // Iterate from the current city to the destination city
    for(int i = this->currentCityId; i <= this->destinationId; i++){
        if(range < 0){
            return distance;    // If range is depleted, return the distance traveled so far
        }
        distance += distanceMap[i];     // Add distance to the next city
        range -= distanceMap[i];        // Subtract distance from the remaining range
    }
    return distance;        // Return total distance if destination is reachable
}



// Implementation of getter methods

int Vehicle::getVehicleId()
{
    return this->vehicleId;
}

int Vehicle::getCurrentCityId()
{
    return this->currentCityId;
}

int Vehicle::getDestinationId()
{
    return this->destinationId;
}

int Vehicle::getCapacityRange()
{
    return this->capacityRange;
}

int Vehicle::getRemainRange()
{
    return this->remainRange;
}


// Implementation of setter methods

void Vehicle::setOrigin(int CurrentCityId)
{
    this->currentCityId = CurrentCityId;
}

void Vehicle::setRemainRange(int RemainRange)
{
    this->remainRange = RemainRange;
}

#endif