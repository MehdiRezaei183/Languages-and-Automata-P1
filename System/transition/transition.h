//
// Created by my pc on 3/25/2025.
//

#ifndef PASSWORDNFA_TRANSITION_H
#define PASSWORDNFA_TRANSITION_H
#include "vector"
#include "set"
#include "string"

using namespace std;
enum class transitionMove{
    _A_Z,
    _a_z,
    _0_9,
    Null
};


class transition {
private:
    transitionMove move;
public:
    transitionMove getMove(){return move;}
    void setMove(transitionMove input){ this->move = input;}

};


#endif //PASSWORDNFA_TRANSITION_H
