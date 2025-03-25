//
// Created by my pc on 3/25/2025.
//

#include "System.h"

transitionMove System::charToTransition(const char& input) {
    if(input <= 'z' && input >='a'){
        return transitionMove ::MOVE_a_z;
    }
    else if(input <= 'Z' && input >='A'){
        return transitionMove ::MOVE_A_Z_;
    }
    else if(input <= '9' && input >='0'){
        return transitionMove ::MOVE_0_9;
    }else{
        return transitionMove ::Move_LL;
    }
}

System ::System() {
    number_lower = 1;
    number_num = 1;
    number_upper =  1;
    number_LL = 1;
    multiset<transitionMove> temp = {transitionMove ::Null};
    mainState = new state(temp);
    makeAutomata();
}
System ::System(int upper, int low , int num ,int  ll) : number_lower(low) , number_num(num),number_upper(upper),number_LL(ll) {
    multiset<transitionMove> temp = {transitionMove ::Null};
    mainState = new state(temp);
    makeFinalState();
    map1[mainState->getStringContainer()] = mainState;
    map1[finalState->getStringContainer()] = finalState;
    transition_limit = {make_pair(transitionMove ::MOVE_A_Z_ , number_upper),
                        make_pair(transitionMove ::MOVE_a_z , number_lower),
                        make_pair(transitionMove ::MOVE_0_9 , number_num),
                        make_pair(transitionMove ::Move_LL,number_LL)
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
    for (int i = 0; i < number_lower; ++i) {
        temp.insert(transitionMove ::MOVE_A_Z_);
    }
    for (int i = 0; i < number_lower; ++i) {
        temp.insert(transitionMove ::Move_LL);
    }

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

string System::IsAvail(state *stat, transitionMove input) {
    multiset<transitionMove > temp = stat->getContainer();
    state test(temp);
    test.addToContainer(input);


    if(map1.find(test.getStringContainer()) != map1.end()){
        return test.getStringContainer();
    }
    return "";
}

void System::printStates(vector<std::string> & input) {
    for (auto & item: input) {
        cout << "{"<< item << "}" << " -> ";
    }
    cout << "END\n";
}


bool System::IsPass(std::string input) {
    state* temp = mainState;
    vector<string> states;
    for (int i = 0; i < input.length(); ++i) {
        states.emplace_back(temp->getStringContainer());
        if(temp == finalState){
            printStates(states);
            return true;
        }
        temp = temp->move(charToTransition(input[i]));
    }
    states.emplace_back(temp->getStringContainer());
    printStates(states);
    if(temp == finalState){
        return true;
    }
    return false;
}