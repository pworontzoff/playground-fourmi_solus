#ifndef PAPER_H_INCLUDED
#define PAPER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define repeat(n) _pile_repeat++;for(_cpt_repeat[_pile_repeat]=0;_cpt_repeat[_pile_repeat]<n;_cpt_repeat[_pile_repeat]++)
#define loop _pile_repeat--

int _cpt_repeat[100];
int _pile_repeat;

struct RGB {
    short red;
    short green;
    short blue;
};

struct colorize_element {
    int numStep;
    struct RGB current_color;
    struct colorize_element *pNext;
};

struct spaper {
    int l;
    int c;
    int nbc;
    int nbl;
    int quad_size;
    int status;
    float anim_duration; //in seconds
    int use_step_display;
    FILE *fp;
    int nbSteps; // number of steps (= number of "colorize' = number of tables)
    struct RGB current_color;
    struct colorize_element *table;
};

struct spaper _paper;

void _init_paper(struct spaper *,int, int, int, float, int);
void _create_table(struct spaper);
void _move_down(struct spaper *);
void _move_up(struct spaper *);
void _move_left(struct spaper *);
void _move_right(struct spaper *);
void _move_to(struct spaper *, int, int);
void _colorize(struct spaper *);
void _erase(struct spaper *);
void _step_display(struct spaper *);
void _change_color(struct spaper *, short, short, short);
int _is_colored(struct spaper);
struct RGB _get_color(struct spaper);
void _create_quad(char *,struct colorize_element *,int, int, int);

void init_paper(int, int, int, float, int);
void display_paper();
void move_down();
void move_up();
void move_left();
void move_right();
void move_to(int, int);
void colorize();
void erase();
void step_display();
void change_color(short, short, short);
int is_colored();
struct RGB get_color();

#endif // PAPER_H_INCLUDED
