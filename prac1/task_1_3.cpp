#include <iostream>
#include <iomanip>

using namespace std;

double dailySales();
void commission(double sales);

int main(){

    commission(dailySales());

    return 0; 
}


double dailySales(){
    double salespersonSales;

    cout << "type your daily sales: ";
    do{

        cin >> salespersonSales;
        if(salespersonSales <= 0)
        {
            cout << "please enter a valid number:\n";
        }
        cin.clear();
        fflush(stdin);

    } while(salespersonSales <= 0);

    
    return salespersonSales;
}

void commission(double sales){

    if(sales <= 999)
    {
        sales *= 0.03;  
        cout << "your commission is " << sales << "$" << '\n';    
    }
    else if(sales <= 2999)
    {
        sales *= 0.035;
        cout << "your commission is " << sales << "$" << '\n';               
    }   
    else
    {
        sales *= 0.045;               
        cout << "your commission is " << sales << "$" << '\n';          
    }

}