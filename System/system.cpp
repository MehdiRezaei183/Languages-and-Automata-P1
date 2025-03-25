//
// Created by my pc on 3/25/2025.
//

#include "system.h"



system ::system() {
    number_lower = 1;
    number_num = 1;
    mainState = new state(transitionMove ::Null);
    makeAutomata();
}
system ::system(int low, int num) :number_lower(low) , number_num(num) {
    mainState = new state(transitionMove::Null);
    makeAutomata();
}

void system::makeAutomata() {

}