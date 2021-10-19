#include <stdio.h>
#include <stdlib.h>
#include "paper.h"

int main()
{
    init_paper(5,5,25,0.25,0);
    repeat(9) {
        if (!is_colored()) {
            colorize();
            move_right();
            colorize();
            move_down();
            colorize();
            move_left();
            colorize();
            move_up();
        } else {
            erase();
            move_right();
            erase();
            move_down();
            erase();
            move_left();
            erase();
            move_up();
        }
    } loop;
    display_paper();    
    return 0;
}
