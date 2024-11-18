#ifndef LOANACCOUNT_H
#define LOANACCOUNT_H
#include "Account.h"
#include <cmath>


class LoanAccount : public Account {

    public:
        LoanAccount(double initialB, double interestR, double t)
        :Account(initialB, interestR,t){}

        double getMonthlyPayment();
};

double LoanAccount::getMonthlyPayment(){
    double rateFraction = interestRate/(12.0*100.0);
    double payment = initialBalance * (rateFraction + rateFraction / (pow(1+rateFraction,term)-1.0));
    return payment;
}

#endif