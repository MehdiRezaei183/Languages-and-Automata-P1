//
// Created by my pc on 3/25/2025.
//

#include "transition.h"
transition ::transition()= default;
transition ::transition(transitionMove input):move(input) {

}
string transitionToString(const transitionMove& input){
    switch (input) {
        case transitionMove::MOVE_A_Z_ :return "MOVE_A_Z_";
        case transitionMove::MOVE_0_9 :return "MOVE_0_9";
        case transitionMove::Null : return "Null";
        case transitionMove::MOVE_a_z : return "MOVE_a_z";
    }
    return "";
}