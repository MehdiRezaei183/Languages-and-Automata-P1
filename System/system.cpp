//
// Created by my pc on 3/25/2025.
//

#include "System.h"



System ::System() {
    number_lower = 1;
    number_num = 1;
    multiset<transitionMove> temp = {transitionMove ::Null};
    mainState = new state(temp);
    makeAutomata();
}
System ::System(int low, int num) : number_lower(low) , number_num(num) {
    multiset<transitionMove> temp = {transitionMove ::Null};
    mainState = new state(temp);
    makeFinalState();
    map1[mainState->getStringContainer()] = mainState;
    map1[finalState->getStringContainer()] = finalState;
    transition_limit = {make_pair(transitionMove ::MOVE_A_Z_ , 1),
                        make_pair(transitionMove ::MOVE_a_z , number_lower),
                        make_pair(transitionMove ::MOVE_0_9 , number_num)
                        };
    makeAutomata();
}

void System::makeFinalState() {
    multiset<transitionMove> temp = {transitionMove ::Null};
    for (int i = 0; i < number_num; ++i) {
        temp.insert(transitionMove ::MOVE_0_9);
    }
    for (int i = 0; i < number_lower; ++i) {
        temp.insert(transitionMove ::MOVE_a_z);
    }
    temp.insert(transitionMove ::MOVE_A_Z_);
    finalState = new state(temp);
}

void System::reversMakeAutomate(state *current) {
    if(current->getContainer() == finalState->getContainer()){
        return;
    }
    for (auto& item: transition_limit) {

        if(current->getContainer().count(item.first) < item.second){
            string temp = IsAvail(current,item.first);
            if(temp != ""){
                current->addMove(transition(item.first),map1[temp]);
            }else{
                state* test = current->make_transition_move(item.first);
                map1[test->getStringContainer()] = test;
            }

        }
    }
    for (auto &item: current->getMoves()) {
        reversMakeAutomate(item.second);
    }
}
void System::makeAutomata() {
    reversMakeAutomate(mainState);
}

string System::IsAvail(state *state, transitionMove input) {
    string temp = state->getStringContainer() + "," + transitionToString(input);
    if(map1.find(temp) != map1.end()){
        return temp;
    }
    return "";
}