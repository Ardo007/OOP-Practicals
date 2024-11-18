#include <iostream>
using namespace std;

void quotientRemainder(int numerator, int denominator);

int main(){

    quotientRemainder(5,2);
    quotientRemainder(10,2);
    quotientRemainder(16,5);

    return 0;
}

void quotientRemainder(int numerator, int denominator){
    cout << "the quotient is " << numerator / denominator << '\n';
    cout << "the remainder is " << numerator % denominator << '\n';
}