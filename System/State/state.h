//
// Created by my pc on 3/25/2025.
//

#ifndef PASSWORDNFA_STATE_H
#define PASSWORDNFA_STATE_H


#include "../transition/transition.h"



class state {
private:
    multiset<transitionMove> container;
    vector<pair<transition , state*>> moves;
public:
    state();
    state(multiset<transitionMove>& input):container(input){}
    multiset<transitionMove> getContainer(){return container;}
    vector<pair<transition , state*>> getMoves(){return moves;}
    state* make_transition_move(transitionMove);
    void addToContainer(transitionMove input);
    void addMove(transition , state* );
    state* move(const transitionMove&);
    string getStringContainer();

};


#endif //PASSWORDNFA_STATE_H
