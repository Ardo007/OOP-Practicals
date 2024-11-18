#include <iostream>
#include <cmath>

using namespace std;


int main() {

    double riverWidth;
    double factoryDistance;
    double costUnderwater;
    double costOverland;

    cout << "enter river width (in meters): ";
    cin >> riverWidth;

    cout << "enter the distance of the factory downstream on the other side of the river (in meters): ";
    cin >> factoryDistance;

    cout << "enter cost of laying powerline underwater (in dollars): ";
    cin >> costUnderwater;

    cout << "enter cost of laying powerline overland (in dollars): ";
    cin >> costOverland;

    double minCost = 10000000000000;
    double best_x = 0;
    double best_y = 0;

    for(double x = 0; x <= factoryDistance; x++){
        double y = sqrt(pow(riverWidth, 2) + pow(x, 2));
        double overlandDist = factoryDistance - x;
        double cost = (y * costUnderwater) + (overlandDist * costOverland);

        if(cost < minCost){
            minCost = cost;
            best_y = y;
            best_x = x;
        }
    }

    cout << "best distance for land for minimal cost is: " << best_x << " meters" << '\n';
    cout << "best distance for underwater for minimal cost is: " << best_y << " meters" << '\n';
    cout << "and the minimal cost for this is: $" << minCost << '\n';

    return 0;
}