#include <iostream>
#include "Constant.h"
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include "Vehicle.h"




using namespace std;

int main (){

    vector <Vehicle> vehicles;


    cout << "Vehicle Id" << setw(20) 
        << "CurrentCity Id " << setw(20) 
        << "Destination Id"  << setw(20) 
        << "Capacity Range" << setw(20) 
        << "Remaining Range" << endl; 


    string lines;

    ifstream file;
    file.open("ChargingDemands.txt");

    if(file.fail()){
        cout << "File not found" << endl;
        return 1;
    }

    while(getline(file, lines)) {
        string temp = "";
        for(int i = 0; i < lines.length();i++){
            if(lines[i] != '[' && lines[i] != ']'){
                temp += lines[i];
            }
        }
        string  vehicleId, destinationId, capacityRange, remainingRange;

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


    for(Vehicle &vehicle : vehicles){
        vehicle.print();
        cout << endl;

    }

    return 0;
}