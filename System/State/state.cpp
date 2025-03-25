//
// Created by my pc on 3/25/2025.
//

#include "state.h"

state ::state()  = default;
void state::addMove(transition move, state * dis) {
    moves.emplace_back(make_pair(move,dis));
}

void state::addToContainer(transitionMove input) {
    container.insert(input);
}

state* state::make_transition_move(transitionMove input) {
    multiset<transitionMove> temp = container;
    temp.insert(input);
    state* newState = new state(temp);
    moves.emplace_back(make_pair(transition(input),newState));
    return newState;
}

string state::getStringContainer() {
    string temp;
    for (auto &item : container) {
        temp += "," + transitionToString(item);
    }
    return temp;
}

state *state::move(const transitionMove& input) {
    for (auto & item: moves) {
        if(item.first.getMove() == input){
            return item.second;
        }
    }
    return this;
}