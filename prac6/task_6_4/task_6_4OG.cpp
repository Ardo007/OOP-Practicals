//Program to demonstrate the CDAccount structure type.
#include <iostream>
#include <cmath>

using namespace std;

//The structure for a bank deposit account:
struct DepositAccount {
    double initialBalance;
    double interestRate;
    int term;//months until maturity
};

//The structure for a bank loan:
struct LoanAccount {
    double initialBalance;
    double interestRate;
    int term;//months until maturity
};

void inputData(DepositAccount& theAccount) {
    cout << "Enter the amount of initial balance: $";
    cin >> theAccount.initialBalance;
    cout << "Enter interest rate percent per annual: ";
    cin >> theAccount.interestRate;
    cout << "Enter the number of months: ";
    cin >> theAccount.term;
}

void inputData(LoanAccount& theAccount) {
    cout << "Enter the amount of initial balance: $";
    cin >> theAccount.initialBalance;
    cout << "Enter interest rate percent per annual: ";
    cin >> theAccount.interestRate;
    cout << "Enter the number of months: ";
    cin >> theAccount.term;
}

double getBalanceAtMaturity (DepositAccount& theAccount) {
	   double rateFraction, interest;
	    rateFraction = theAccount.interestRate/100.0;
	    interest = theAccount.initialBalance*(rateFraction*(theAccount.term/12.0));//simple interest
	    double balanceAtMaturity = theAccount.initialBalance + interest;
        return balanceAtMaturity;
}

double getMonthlyPayment(LoanAccount& theAccount) {
	    double rateFraction = theAccount.interestRate/(12.0*100.0);
	    double payment = theAccount.initialBalance * (rateFraction + rateFraction / (pow(1+rateFraction,theAccount.term)-1.0));//simple interest
	    return payment;
}

int main( )
{
    //test deposit account
	cout << "Test deposit account --- " << endl;
	DepositAccount dAccount;
    inputData(dAccount);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "The balance of deposit at maturity is $"
         << getBalanceAtMaturity(dAccount) <<" after " << dAccount.term << " months."<< endl;

    //test loan account
	cout << "\nTest loan account --- " << endl;
	LoanAccount lAccount;
    inputData(lAccount);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "The monthly payment of the loan is $"
         << getMonthlyPayment(lAccount) <<" for " << lAccount.term << " months."<< endl;
    return 0;
}