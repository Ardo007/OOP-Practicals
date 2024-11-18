/*
     Decleration:
     I hold a copy of this assignment that I can produce if the original is lost or damaged. 
     I hereby certify that no part of this assignment has been copied from any other student’s work or 
     from any other source except where due acknowledgement is made in the assignment. No part 
     of this assignment has been written/produced for me by another person except where such 
     collaboration has been authorised by the subject lecturer concerned.
     Compiler used: GCC, IDE: VSCode
*/



#include <iostream>
#include "Constant.h"
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include "Vehicle.h"
#include "ChargingStation.h"
#include "DemandGenerator.h"
#include "ChargingAllocation.h"

using namespace std;

int main()
{
     int choice;
    cout << "choose which file to open: \n"
         << "1. Fixed Demands\n"
         << "2. Random Demands\n";
     cin >>  choice;


    DemandGenerator demand;
    ChargingAllocation allocation(choice);

    demand.generateDemands();

    cout << "*************************************************************************************************\n";
    cout << "Vehicle Id" << setw(20)
         << "CurrentCity Id " << setw(20)
         << "Destination Id" << setw(20)
         << "Capacity Range" << setw(20)
         << "Remaining Range" << endl;
    cout << "*************************************************************************************************\n";

    allocation.readFile();
    allocation.displayVehicles();


    cout << "*************************************************************************************************\n";
    cout << "Charging Station Info: \n";
    cout << "city Id" << setw(25)
         << "City/charging station" << setw(25)
         << "Distance to last city" << setw(20)
         << "Number of chargers" << endl;
    cout << "*************************************************************************************************\n";

    allocation.displayStations();


    cout << "**************************************************************************************************************************************\n";
    cout << "allocating stations: \n";
    cout << "Vehicle Id" << setw(20)
         << "CurrentCity Id " << setw(20)
         << "Destination Id" << setw(20)
         << "Capacity Range" << setw(20)
         << "Remaining Range" << setw(20)
         << "First Charge" << setw(20)
         << "Second Charge" << endl;
    cout << "**************************************************************************************************************************************\n";

    allocation.printAllocations();

     cout << "**************************************************************************************************************************************\n";
     cout << "Average Waiting Time: \n";
     cout << "LocationId" << setw(20) 
          << "Location Name" << setw(20)
          << "Distance To Sydney" << setw(20)
          << "No. of Chargers" << setw(20)
          << "Queue Length" << setw(20)
          << "Waiting Hours" << endl;
     cout << "**************************************************************************************************************************************\n";

     allocation.displayWaitTime();
     cout << "The Overall Average Waiting time is: ";
     allocation.overallWaitTime();
     cout << allocation.getWaitingTime();
     cout << endl;

     cout << "**************************************************************************************************************************************\n";
     cout << "Attempting to balance out waiting times: \n";     
     cout << "**************************************************************************************************************************************\n";
     cout << "allocating stations: \n";
     cout << "Vehicle Id" << setw(20)
          << "CurrentCity Id " << setw(20)
          << "Destination Id" << setw(20)
          << "Capacity Range" << setw(20)
          << "Remaining Range" << setw(20)
          << "First Charge" << setw(20)
          << "Second Charge" << endl;
     cout << "**************************************************************************************************************************************\n";
     allocation.simulateCharging(5000);
     cout << endl;
     
     cout << "**************************************************************************************************************************************\n";
     cout << "Average Waiting Time: \n";
     cout << "LocationId" << setw(20) 
          << "Location Name" << setw(20)
          << "Distance To Sydney" << setw(20)
          << "No. of Chargers" << setw(20)
          << "Queue Length" << setw(20)
          << "Waiting Hours" << endl;
     cout << "**************************************************************************************************************************************\n";
     allocation.displayWaitTime();
     cout << "The Overall Average Waiting time after 5000 simulations is: "
          << allocation.getWaitingTime()
          << " hours";

    return 0;
}