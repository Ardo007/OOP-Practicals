#include <iostream>
#include <cmath>
#include "Account.h"
#include "DepositAccount.h"
#include "LoanAccount.h"

using namespace std;

void inputData(double& bal, double& rate, int& ter) {
    cout << "Enter the amount of initial balance: $";
    cin >> bal;
    cout << "Enter interest rate percent per annual: ";
    cin >> rate;
    cout << "Enter the number of months: ";
    cin >> ter;
}

int main(){
    double balance, intRate;
    int term;

    //test deposit account
	cout << "Test deposit account --- " << endl;
    inputData(balance, intRate, term);

    DepositAccount d(balance, intRate, term);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "The balance of deposit at maturity is $"
         << d.getBalanceAtMaturity() <<" after " << term << " months."<< endl;

    // test loan account
	cout << "\nTest loan account --- " << endl;
    inputData(balance, intRate, term);

	LoanAccount L(balance, intRate, term);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "The monthly payment of the loan is $"
         << L.getMonthlyPayment() <<" for " << term << " months."<< endl;

    return 0;
}