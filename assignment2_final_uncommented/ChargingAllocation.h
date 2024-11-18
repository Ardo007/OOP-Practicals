#ifndef CHARGINGALLOCATION_H
#define CHARGINGALLOCATION_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Constant.h"
#include <iomanip>
#include "Vehicle.h"
#include "ChargingStation.h"
#include "DemandGenerator.h"
#include <limits>


class ChargingAllocation {

    private:
        vector<Vehicle> vehicles;
        vector<ChargingStation> stations;
        double waitingTime;
        int fileToOpen;

    public:

        void readFile();
        void displayVehicles();
        void displayStations();
        string oneCharge(Vehicle *Vehicle);
        int findClosestStation(int range);
        ChargingStation *assign(int stationId);
        void printAllocations();
        void displayWaitTime();
        void overallWaitTime();
        string oneChargeRandom(Vehicle *Vehicle);
        void simulateCharging(int num);
        double getWaitingTime();



 
        ChargingAllocation(int file){
            for(int i = 0; i < NUM_CITIES; i++){
                ChargingStation station(i);
                stations.push_back(station);
            }
            fileToOpen = file;
        }


};


double ChargingAllocation::getWaitingTime(){
    return this->waitingTime;
}


void ChargingAllocation::readFile(){
    string lines;

    ifstream file;

    if(fileToOpen == 1)
    {
        file.open("ChargingDemands.txt");
    }
    else if(fileToOpen == 2)
    {
        file.open("RandomDemands.txt");
    }

    if (file.fail())
    {
        cout << "File not found" << endl;
        exit(1);
    }

    while (getline(file, lines))
    {
        string temp = "";

        for (int i = 0; i < lines.length(); i++)
        {
            if (lines[i] != '[' && lines[i] != ']')
            {
                temp += lines[i];
            }
        }
        string vehicleId, destinationId, capacityRange, remainingRange;


        int pos = temp.find(',');
        vehicleId = temp.substr(0, pos);

        temp = temp.substr(pos + 1);
        pos = temp.find(',');
        destinationId = temp.substr(0, pos);

        temp = temp.substr(pos + 1);
        pos = temp.find(',');
        capacityRange = temp.substr(0, pos);

        temp = temp.substr(pos + 1);
        remainingRange = temp;

        int vehicleID = stoi(vehicleId);
        int destinationID = stoi(destinationId);
        int capacityRangeInt = stoi(capacityRange);
        int remainingRangeInt = stoi(remainingRange);

        Vehicle vehicle(vehicleID, 0, destinationID, capacityRangeInt, remainingRangeInt);
        vehicles.push_back(vehicle);
    }

    file.close();
}



void ChargingAllocation::displayVehicles(){

    for (Vehicle &vehicle : vehicles) 
    {
        vehicle.print();
        cout << endl;
    }
}



void ChargingAllocation::displayStations(){

    for(ChargingStation &station : stations) 
    {
        station.printStation();
        cout << endl;
    }
}



string ChargingAllocation::oneCharge(Vehicle *Vehicle){
    int remainRange = Vehicle->getRemainRange();
    int DestDistance = this->stations[Vehicle->getDestinationId()].distanceToSydney();
    int currentDistance = this->stations[Vehicle->getCurrentCityId()].distanceToSydney();
    int distanceToTravel = DestDistance - currentDistance;

    if(remainRange < distanceToTravel){

        int closestStation = findClosestStation(currentDistance + remainRange);

        if(closestStation >= 0){
            ChargingStation *station = assign(closestStation);
            station->increaseQueue();   

            
            Vehicle->setRemainRange(Vehicle->getCapacityRange());
            Vehicle->setOrigin(closestStation);

            return station->getCityName();  
        }
    }

    return "----"; 

}




int ChargingAllocation::findClosestStation(int range){
    int Station = -1;

    for(int i = 0; i < NUM_CITIES; i++){
        if(stations[i].distanceToSydney() >= range){
            return i - 1;   
        }
    }
    return Station;     
}



ChargingStation *ChargingAllocation::assign(int stationId){
    return  &this->stations[stationId];

}


void ChargingAllocation::printAllocations(){

    vector<Vehicle> initialVehicles = this->vehicles;

    for(Vehicle vehicle : vehicles){
        vehicle.print();

        string firstCharge = oneCharge(&vehicle);       
        cout << setw(20) << firstCharge;

        string secondCharge = oneCharge(&vehicle);     
        cout << setw(20) << secondCharge;
        cout << endl;
    }

    this->vehicles = initialVehicles;       
}

void ChargingAllocation::displayWaitTime(){
        for(int i = 0; i < this->stations.size(); i++) 
        {
            stations[i].printStation();

            
            cout << setw(20) << stations[i].getQueue()
                << setw(20) << stations[i].AverageWaitTime() << " hours";
            cout << endl;
        }
}




void ChargingAllocation::overallWaitTime(){
    double sumOfQueues = 0;
    double waitingTimes = 0;
    for(ChargingStation station : stations){
        
        sumOfQueues += station.getQueue();    
        waitingTimes += station.getQueue() * station.AverageWaitTime();    
    }
    double answer = (1/sumOfQueues)*waitingTimes;    
    this->waitingTime = answer;     
}


string ChargingAllocation::oneChargeRandom(Vehicle *Vehicle){
    int remainRange = Vehicle->getRemainRange();
    int DestDistance = this->stations[Vehicle->getDestinationId()].distanceToSydney();
    int currentDistance = this->stations[Vehicle->getCurrentCityId()].distanceToSydney();
    int distanceToTravel = DestDistance - currentDistance;

    if(remainRange <= distanceToTravel){

        int randomRangeUsed = rand() % remainRange + 1;
        int totalTravelDistance = currentDistance + randomRangeUsed;
        int closestStation = findClosestStation(totalTravelDistance);

        if(closestStation >= 0){
            ChargingStation *station = assign(closestStation);
            station->increaseQueue();


            Vehicle->setRemainRange(Vehicle->getCapacityRange());
            Vehicle->setOrigin(closestStation);
            return station->getCityName();
        }
    }

    return "----";
}


void ChargingAllocation::simulateCharging(int numOfSims){
    vector<Vehicle> starterVehicles = this->vehicles;   
    vector<Vehicle> temp = this->vehicles;      
    vector<ChargingStation> newStations = this->stations;       

    srand(time(0));

    double newWaitingTime = numeric_limits<double>::max();  
    int simCounter = 0;

    while(simCounter < numOfSims){

        for(ChargingStation &station : stations){
            station.setQueue();
        }

        temp = starterVehicles; 

        for(Vehicle vehicles : temp){

            if(simCounter == numOfSims-1){
                vehicles.print();
            }

            string firstCharge = oneChargeRandom(&vehicles);
            if(simCounter == numOfSims-1){
                cout << setw(20) << firstCharge;
            }

            string secondCharge = oneChargeRandom(&vehicles);
            if(simCounter == numOfSims-1){
                cout << setw(20) << secondCharge;
                cout << endl;
            }
        }

        overallWaitTime();      
        double improvWaitingTime = waitingTime; 

        
        if(improvWaitingTime < newWaitingTime){
            newStations = this->stations;
            this->vehicles = temp;
            newWaitingTime = improvWaitingTime;
        }
        simCounter++;
    }
    
    this->stations = newStations;
    this->waitingTime = newWaitingTime;

}


#endif