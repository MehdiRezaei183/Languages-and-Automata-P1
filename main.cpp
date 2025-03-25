#include <iostream>
#include "System/System.h"

int main() {
    int upper , lower , number , LL;
    cout << "A-Z : ";
    cin >> upper;
    cout << "a-z : ";
    cin >> lower;
    cout << "0-9 : ";
    cin >> number;
    cout << "LL : ";
    cin >> LL;

    System test(upper , lower , number , LL);
    cout << "PassWord : ";
    string  input;
    cin >> input;
    if(test.IsPass(input)){
        cout << "GOOD";
    }
    else{
        cout << "BAD";
    }
    return 0;
}
