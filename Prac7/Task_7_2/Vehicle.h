#ifndef VEHICLE_H_
#define VEHICLE_H_
#include <iostream>
#include <string>
#include <iomanip>
#include "Constant.h"
using namespace std;


class Vehicle {
    public:
        int vehicleId;
        int currentCityId;
        int destinationId;
        int capacityRange;
        int remainRange;

        Vehicle(int VehicleId, int CurrentCityId, int DestinationId, int CapacityRange, int RemainRange){
            vehicleId =  VehicleId;
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

        void setCurrentCityId(int CurrentCityId);
        void setRemainRange(int RemainRange);

        void print();

};

void Vehicle::print(){
    cout << setw(5) << vehicleId;
    cout << setw(20) << nameMap[currentCityId];
    cout << setw(20) << nameMap[destinationId];
    cout << setw(20) << capacityRange;
    cout << setw(20) << remainRange;
}



int Vehicle::getVehicleId(){
    return this->vehicleId;
}

int Vehicle::getCurrentCityId(){
    return this->currentCityId;
}

int Vehicle::getDestinationId(){
    return this->destinationId;
}

int Vehicle::getCapacityRange(){
    return this->capacityRange;
}

int  Vehicle::getRemainRange(){
    return this->remainRange;
}

void Vehicle::setCurrentCityId(int CurrentCityId){
    this->currentCityId = CurrentCityId;
}

void  Vehicle::setRemainRange(int RemainRange){
    this->remainRange = RemainRange;
}




#endif