#ifndef VEHICLE_H_
#define VEHICLE_H_
#include <iostream>
#include <string>
#include <iomanip>
#include "Constant.h"
#include "ChargingStation.h"
using namespace std;

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

void Vehicle::print()
{
    cout << setw(5) << vehicleId;
    cout << setw(20) << nameMap[currentCityId];
    cout << setw(20) << nameMap[destinationId];
    cout << setw(20) << capacityRange;
    cout << setw(20) << remainRange;
}

int Vehicle::furthestCityToTravelTo(){
    int distance = 0;
    int range = this->remainRange;
    for(int i = this->currentCityId; i <= this->destinationId; i++){
        if(range < 0){
            return distance;
        }
        distance += distanceMap[i];
        range -= distanceMap[i];
    }
    return distance;
}


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

void Vehicle::setOrigin(int CurrentCityId)
{
    this->currentCityId = CurrentCityId;
}

void Vehicle::setRemainRange(int RemainRange)
{
    if(remainRange <=0){
        cout << "Error: Remain Range is not enough to travel to destination." << endl;
        exit(1);
    }

    if(remainRange > this->capacityRange){
        cout << "Error: Remain Range is more than capacity." << endl;
        exit(1);
    }

    this->remainRange = RemainRange;
}

#endif