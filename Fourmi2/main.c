#include <stdio.h>
#include <stdlib.h>
#include "paper.h"

#define up    1
#define right 2
#define down  3
#define left  4

int ant_looks = right; // (up is 1 / right is 2 / down is 3 / left is 4)

void ant_turns_left_then_move();
void ant_turns_right_then_move();

int main()
{
    init_paper(15,15,25,0.1,0);
    
    move_to(7,7);
    repeat(96) {
        if (!is_colored()) {
            colorize();
            ant_turns_right_then_move();
        } else {
            erase();
            ant_turns_left_then_move();
        }
    } loop;
    display_paper();    
    return 0;
}

void ant_turns_right_then_move() {
    switch (ant_looks) {
        case up : // ant looks up
            ant_looks = right;
            move_right();
            break;
        case right : // ant looks right
            ant_looks = down;
            move_down();
            break; 
        case down : // ant looks down
            ant_looks = left;
            move_left();
            break;
        case left : // ant looks left
            ant_looks = up;
            move_up();
            break; 
    }
}

void ant_turns_left_then_move() {
    switch (ant_looks) {
        case up : // ant looks up
            ant_looks = left;
            move_left();
            break;
        case left : // ant looks left
            ant_looks = down;
            move_down();
            break; 
        case down : // ant looks down
            ant_looks = right;
            move_right();
            break;
        case right : // ant looks right
            ant_looks = up;
            move_up();
            break; 
    }
}
