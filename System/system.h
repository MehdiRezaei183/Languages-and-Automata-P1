//
// Created by my pc on 3/25/2025.
//

#ifndef PASSWORDNFA_SYSTEM_H
#define PASSWORDNFA_SYSTEM_H
#include "/State/state.h"


class system {
private:
    state* mainState;
    int number_lower;
    int number_num;
public:
    system();
    system(int , int );
    void setNumber_lower(int input){ this->number_lower = input;}
    void setNumber_num(int input){ this->number_num = input;}

    void makeAutomata();
};


#endif //PASSWORDNFA_SYSTEM_H
