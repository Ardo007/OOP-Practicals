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

/**
 * @class ChargingAllocation
 * @brief Manages the allocation of vehicles to charging stations.
 * 
 * This class handles reading vehicle data from files, assigning vehicles to
 * the closest available charging stations, calculating waiting times, and
 * simulating charging scenarios.
 */
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



        /**
         * @brief Constructor for ChargingAllocation.
         * 
         * Initializes charging stations based on the number of cities and sets
         * the file to open for reading vehicle data.
         * 
         * @param file Indicator for which file to open (1 or 2)
         */
        ChargingAllocation(int file){
            for(int i = 0; i < NUM_CITIES; i++){
                ChargingStation station(i);
                stations.push_back(station);
            }
            fileToOpen = file;
        }


};


/**
 * @brief Retrieves the overall waiting time.
 * 
 * @return double representing the total waiting time.
 */
double ChargingAllocation::getWaitingTime(){
    return this->waitingTime;
}



/**
 * @brief Reads vehicle data from a file based on the fileToOpen indicator.
 * 
 * Parses each line to extract vehicle details and adds them to the vehicles list.
 */
void ChargingAllocation::readFile(){
    string lines;

    ifstream file;

    // Determine which file to open based on fileToOpen
    if(fileToOpen == 1)
    {
        file.open("ChargingDemands.txt");
    }
    else if(fileToOpen == 2)
    {
        file.open("RandomDemands.txt");
    }

    // Check if file opening failed
    if (file.fail())
    {
        cout << "File not found" << endl;
        exit(1);
    }

    // Read each line from the file
    while (getline(file, lines))
    {
        string temp = "";

        // Remove square brackets from the line
        for (int i = 0; i < lines.length(); i++)
        {
            if (lines[i] != '[' && lines[i] != ']')
            {
                temp += lines[i];
            }
        }
        string vehicleId, destinationId, capacityRange, remainingRange;


        // separate each number into different strings
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

        // Convert string values to integers
        int vehicleID = stoi(vehicleId);
        int destinationID = stoi(destinationId);
        int capacityRangeInt = stoi(capacityRange);
        int remainingRangeInt = stoi(remainingRange);

        // Create a Vehicle object and add to the vehicles vector
        Vehicle vehicle(vehicleID, 0, destinationID, capacityRangeInt, remainingRangeInt);
        vehicles.push_back(vehicle);
    }

    file.close();
}


/**
 * @brief Displays all vehicles by invoking their print method.
 */
void ChargingAllocation::displayVehicles(){

    for (Vehicle &vehicle : vehicles) 
    {
        vehicle.print();
        cout << endl;
    }
}


/**
 * @brief Displays all charging stations by invoking their printStation method.
 */
void ChargingAllocation::displayStations(){

    for(ChargingStation &station : stations) 
    {
        station.printStation();
        cout << endl;
    }
}


/**
 * @brief Allocates a single charge for a given vehicle.
 * 
 * Determines if the vehicle needs to charge based on remaining range and
 * assigns it to the closest suitable charging station.
 * 
 * @param Vehicle Pointer to the vehicle to allocate charge
 * @return string Name of the assigned charging station or "----" if no charge needed
 */
string ChargingAllocation::oneCharge(Vehicle *Vehicle){
    int remainRange = Vehicle->getRemainRange();
    int DestDistance = this->stations[Vehicle->getDestinationId()].distanceToSydney();
    int currentDistance = this->stations[Vehicle->getCurrentCityId()].distanceToSydney();
    int distanceToTravel = DestDistance - currentDistance;

    // Check if the remaining range is insufficient to reach the destination
    if(remainRange < distanceToTravel){

        // Find the closest station within the remaining range
        int closestStation = findClosestStation(currentDistance + remainRange);

        // checks if a station charging was needed at a station
        if(closestStation >= 0){
            // Assign the vehicle to the closest station
            ChargingStation *station = assign(closestStation);
            station->increaseQueue();   // Increment the queue at the station

            
            // Reset/refuel the vehicle's range after charging
            Vehicle->setRemainRange(Vehicle->getCapacityRange());
            Vehicle->setOrigin(closestStation);

            return station->getCityName();  // Return the name of the assigned station
        }
    }

    return "----";  // No charging needed

}



/**
 * @brief Finds the closest charging station within a specified range.
 * 
 * Iterates through all stations to find the one closest to the given range.
 * 
 * @param range The maximum distance the vehicle can travel without charging
 * @return int The ID of the closest station, or -1 if none found
 */
int ChargingAllocation::findClosestStation(int range){
    int Station = -1;

    for(int i = 0; i < NUM_CITIES; i++){
        if(stations[i].distanceToSydney() >= range){
            return i - 1;   // Return the station just before exceeding the range
        }
    }
    return Station;     // Return -1 if no suitable station is found
}



/**
 * @brief Assigns a charging station based on its ID.
 * 
 * @param stationId The ID of the station to assign
 * @return ChargingStation* Pointer to the assigned charging station
 */
ChargingStation *ChargingAllocation::assign(int stationId){
    return  &this->stations[stationId];

}


/**
 * @brief Prints the allocation of vehicles to charging stations.
 * 
 * For each vehicle, it prints the vehicle details and the first and second
 * charging station allocations.
 */
void ChargingAllocation::printAllocations(){
    // keep initial state of vehicles
    vector<Vehicle> initialVehicles = this->vehicles;

    for(Vehicle vehicle : vehicles){
        vehicle.print();

        string firstCharge = oneCharge(&vehicle);       // first charge
        cout << setw(20) << firstCharge;

        string secondCharge = oneCharge(&vehicle);      // second charge
        cout << setw(20) << secondCharge;
        cout << endl;
    }

    this->vehicles = initialVehicles;       // restore the vehicles to their initial state
}


/**
 * @brief Displays the waiting time at each charging station.
 * 
 * For each station, it prints the station details, the queue length,
 * and the average waiting time.
 */
void ChargingAllocation::displayWaitTime(){
        for(int i = 0; i < this->stations.size(); i++) 
        {
            stations[i].printStation();

            // Print the queue length and average waiting time
            cout << setw(20) << stations[i].getQueue()
                << setw(20) << stations[i].AverageWaitTime() << " hours";
            cout << endl;
        }
}



/**
 * @brief Calculates the overall waiting time across all charging stations.
 * 
 * It computes a weighted average based on the queue length and waiting time
 * at each station.
 */
void ChargingAllocation::overallWaitTime(){
    double sumOfQueues = 0;
    double waitingTimes = 0;
    for(ChargingStation station : stations){
        
        sumOfQueues += station.getQueue();    // Sum of all queues
        waitingTimes += station.getQueue() * station.AverageWaitTime();    // Weighted sum of waiting times
    }
    double answer = (1/sumOfQueues)*waitingTimes;    // Calculate average waiting time
    this->waitingTime = answer;     // Store the result
}


/**
 * @brief Allocates a charge randomly for a given vehicle.
 * 
 * This method is used for simulation purposes, where the charging point
 * is selected randomly within the remaining range.
 * 
 * @param Vehicle Pointer to the vehicle to allocate charge
 * @return string Name of the assigned charging station or "----" if no charge needed
 */
string ChargingAllocation::oneChargeRandom(Vehicle *Vehicle){
    int remainRange = Vehicle->getRemainRange();
    int DestDistance = this->stations[Vehicle->getDestinationId()].distanceToSydney();
    int currentDistance = this->stations[Vehicle->getCurrentCityId()].distanceToSydney();
    int distanceToTravel = DestDistance - currentDistance;

    // Check if the remaining range is insufficient to reach the destination
    if(remainRange <= distanceToTravel){

         // Randomly determine how much range to use
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


/**
 * @brief Simulates the charging process over a specified number of iterations.
 * 
 * For each simulation, it resets station queues, allocates charging for each vehicle,
 * calculates the overall waiting time, and keeps track of the best (minimum) waiting time.
 * 
 * @param numOfSims The number of simulation iterations to perform
 */
void ChargingAllocation::simulateCharging(int numOfSims){
    vector<Vehicle> starterVehicles = this->vehicles;   // Preserve initial vehicle states
    vector<Vehicle> temp = this->vehicles;      // Temporary vehicle list for simulation
    vector<ChargingStation> newStations = this->stations;       // Temporary station list for best scenario

    srand(time(0));

    double newWaitingTime = numeric_limits<double>::max();  // Initialize with maximum possible value
    int simCounter = 0;

    while(simCounter < numOfSims){
        // Reset queues at all stations for each simulation
        for(ChargingStation &station : stations){
            station.setQueue();
        }

        temp = starterVehicles; // Reset vehicles to initial state

        for(Vehicle vehicles : temp){

            if(simCounter == numOfSims-1){
                vehicles.print();
            }

            // Allocate first random charge
            string firstCharge = oneChargeRandom(&vehicles);
            if(simCounter == numOfSims-1){
                cout << setw(20) << firstCharge;
            }

            // Allocate second random charge 
            string secondCharge = oneChargeRandom(&vehicles);
            if(simCounter == numOfSims-1){
                cout << setw(20) << secondCharge;
                cout << endl;
            }
        }

        overallWaitTime();      // Calculate the overall waiting time
        double improvWaitingTime = waitingTime; // Current simulation's waiting time

        // Update best waiting time and station allocations if improved
        if(improvWaitingTime < newWaitingTime){
            newStations = this->stations;
            this->vehicles = temp;
            newWaitingTime = improvWaitingTime;
        }
        simCounter++;
    }
    
    // After all simulations, set the stations and waiting time to the best found
    this->stations = newStations;
    this->waitingTime = newWaitingTime;

}


#endif