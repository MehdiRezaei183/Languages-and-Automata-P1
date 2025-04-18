//
// Created by my pc on 3/25/2025.
//

#ifndef PASSWORDNFA_SYSTEM_H
#define PASSWORDNFA_SYSTEM_H
#include "State/state.h"
#include "map"
#include "iostream"

class System {
private:
    state* mainState;
    state* finalState;
    int number_lower;
    int number_num;
    int number_upper;
    int number_LL;
    vector<pair<transitionMove , int>> transition_limit;
    map<string , state*> map1;

    vector<pair<string , pair<transitionMove , string>>> table;

    void reversMakeAutomate(state * , map<string , bool>&);
    string IsAvail(state* , transitionMove);
    transitionMove charToTransition(const char& );

public:
    System();
    System(int , int , int ,int );
    void setNumber_lower(int input){ this->number_lower = input;}
    void setNumber_num(int input){ this->number_num = input;}
    void makeFinalState();
    void makeAutomata();

    bool IsPass(string );
    void printStates(vector<string>&);
    void makeTable(state* );
    void printAll();
};


#endif //PASSWORDNFA_SYSTEM_H
