//
// Created by my pc on 3/25/2025.
//

#ifndef PASSWORDNFA_SYSTEM_H
#define PASSWORDNFA_SYSTEM_H
#include "State/state.h"
#include "map"

class System {
private:
    state* mainState;
    state* finalState;
    int number_lower;
    int number_num;
    vector<pair<transitionMove , int>> transition_limit;
    map<string , state*> map1;


    void reversMakeAutomate(state *);
    string IsAvail(state* , transitionMove);

public:
    System();
    System(int , int );
    void setNumber_lower(int input){ this->number_lower = input;}
    void setNumber_num(int input){ this->number_num = input;}
    void makeFinalState();
    void makeAutomata();
};


#endif //PASSWORDNFA_SYSTEM_H
