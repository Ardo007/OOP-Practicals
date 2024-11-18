#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

    int month, day;

    cout << "welcone to your friendly weather program.\n" << "Enter today's date as two integers for the month and the day:\n";
    cout << "enter the month: \n";

    do{
        cin >> month;

        if(month < 1 || month > 12){
            cout << "invalid month enter again: \n";
        }

        cin.clear();
        fflush(stdin);


    }while (month < 1 || month > 12);

    cout << "now enter the day: \n";

    do{
        cin >> day;

        if(day < 1 || day > 31){
            cout << "invalid day enter again: \n";
        }

        cin.clear();
        fflush(stdin);


    }while (day < 1 || day > 31);

    // cin >> day;

    srand(month * day);

    int prediction;
    char ans;

    cout << "Weather for today:\n";

    do {
        prediction = rand() % 3;

        switch (prediction)
        {
        case 0:
            cout << "The day will be sunny!\n";
            break;
        case 1:
            cout << "The day will be cloudy/\n";
            break;
        case 2: 
            cout << "The day will be stormy!.\n";
            break;
        default:
            cout << "Weather program is not functioning";
        }

        cout << "Want the weather for the next day?(y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    cout << "That's it from your 24 hour weather program.\n";

    return 0;
}