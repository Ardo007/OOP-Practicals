#ifndef DEPOSITACCOUNT_H
#define DEPOSITACCOUNT_H
#include "Account.h"


class DepositAccount : public Account {

    public:
        DepositAccount(double initialB, double interestR, double t)
        :Account(initialB, interestR,t){}

        double getBalanceAtMaturity(){
            double rateFraction, interest;
            rateFraction = interestRate/100.0;
            interest = initialBalance*(rateFraction*(term/12.0));
            double balanceAtMaturity = initialBalance + interest;
            return balanceAtMaturity;
        };

};





#endif