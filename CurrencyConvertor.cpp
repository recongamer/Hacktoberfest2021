
// This is program to convert given amount of cents into dollar, quarter, dime, nickel, penny.

#include <iostream>
using namespace std;

int main(){
    int cents=0;
    cout<<"Enter an amounts in cents: ";
    cin >> cents;
    cout<<"You can provide change for this as follows: "<<endl;
    int dollar, quarter, dime, nickel, penny;

    dollar = quarter = dime = nickel = penny = 0;
    if(cents >= 100){
        dollar = cents / 100;
        cents = cents % 100;
    }

    if(cents >= 25){
        quarter = cents / 25;
        cents = cents % 25;
    }

    if(cents >= 10){
        dime = cents / 10;
        cents = cents % 10;
    }

    if(cents >= 5){
        nickel = cents / 5;
        cents = cents % 5;
    }

    if(cents >= 1){
        penny = cents / 1;
        cents = cents % 1;
    }

    cout <<"dollar  : "<<dollar<<endl;
    cout <<"quarter : "<<quarter<<endl;
    cout <<"dime    : "<<dime<<endl;
    cout <<"nickel  : "<<nickel<<endl;
    cout <<"penny   : "<<penny<<endl;
}

// SAMPLE OUTPUT

/*
    Enter an amounts in cents: 356
    You can provide change for this as follows: 
      dollar  : 3
      quarter : 2
      dime    : 0
      nickel  : 1
      penny   : 1
*/
