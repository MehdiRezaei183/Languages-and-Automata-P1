//
// Created by my pc on 3/25/2025.
//

#include "state.h"
state ::state() = default
state ::state(transitionMove input) {
    container.insert(input);
}

void state::addMove(transition move, state * dis) {
    moves.emplace_back(make_pair(move,dis));
}

void state::addToContainer(transitionMove input) {
    container.insert(input);
}