#include <iostream>
#include "Constant.h"
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>



using namespace std;

int main (){

    cout << "Vehicle Id" << setw(20) << "Destination Id" << setw(20)
         << "Capacity Range" << setw(20) << "Remaining Range" << endl; 


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

        cout << setw(5) << vehicleID;
        cout << setw(20) << nameMap[destinationID - 1];
        cout << setw(20) << capacityRangeInt;
        cout << setw(20) << remainingRangeInt;
        cout << endl;  

    }


    file.close();

    return 0;
}