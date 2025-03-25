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
    Null,
    MOVE_A_Z_,
    MOVE_a_z,
    MOVE_0_9,
    Move_LL,
};
string transitionToString(const transitionMove&);

class transition {
private:
    transitionMove move;
public:
    transition();
    transition(transitionMove);
    transitionMove getMove(){return move;}
    void setMove(transitionMove input){ this->move = input;}

};


#endif //PASSWORDNFA_TRANSITION_H
