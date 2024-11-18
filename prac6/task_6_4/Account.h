#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
    private:

    protected:
        double initialBalance;
        double interestRate;
        int term;
    public:
        Account(double initialB, double interestR, double t) {
            initialBalance = initialB;
            interestRate = interestR;
            term = t;
        }

    double getBalanceAtMaturity();
    double getMonthlyPayment();
    ~Account(){};
};


#endif