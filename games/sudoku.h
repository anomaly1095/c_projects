

#if !defined(SUDOKU_H)
#define SUDOKU_H 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Game{
    char  *player_name;
    char lvl;
    char **grid;
}Game;

typedef struct Node{
    char val;
    char rep;
}Node;

#define LEN_NAME    0x1E

#define ONE         0X31
#define TWO         0X32
#define THREE       0X33
#define FOUR        0X34
#define FIVE        0X35
#define SIX         0X36
#define SEVEN       0X37
#define EIGHT       0X38
#define NINE        0X39

#define MAX_REP_L1  0X4
#define MAX_REP_L2  0X3
#define MAX_REP_L3  0X3
#define MAX_REP_L4  0X2
#define MAX_REP_L5  0X2

#define REST_REP_L1  04
#define REST_REP_L2  010
#define REST_REP_L3  03
#define REST_REP_L4  07
#define REST_REP_L5  02


#define RANGE       0x9
#define MIN_VAL     0x31
#define MIN_INDEX   0x0
#define _MASK       0b110000


Node nodes[9] = {
        [0].val = ONE, [0].rep = 0x0,
        [1].val = TWO, [1].rep = 0x0,
        [2].val = THREE, [2].rep = 0x0,
        [3].val = FOUR, [3].rep = 0x0,
        [4].val = FIVE, [4].rep = 0x0,
        [5].val = SIX, [5].rep = 0x0,
        [6].val = SEVEN, [6].rep = 0x0,
        [7].val = EIGHT, [7].rep = 0x0,
        [8].val = NINE, [8].rep = 0x0,
    };

int main(); // stack lvl1
void help();

//#########################SETUP###############################
Game *start_game(); // stack lvl2

char **initialize_Grid(); // stack lvl3
void fill_grid(Game *game); // stack lvl3

void fill_lvl1(char **grid); // stack lvl4
void fill_lvl2(char **grid); // stack lvl4
void fill_lvl3(char **grid); // stack lvl4
void fill_lvl4(char **grid); // stack lvl4
void fill_lvl5(char **grid); // stack lvl4

char can_insert(char **grid, char val, char row, char col); // stack lvl5
char check_insert_row(char **grid, char val, char row); // stack lvl6
char check_insert_col(char **grid, char val, char col); // stack lvl6
char check_insert_subgrid(char **grid, char val, char row, char col); // stack lvl6

char check_insert_subgrid1(char **grid, char val); // stack lvl7
char check_insert_subgrid2(char **grid, char val); // stack lvl7
char check_insert_subgrid3(char **grid, char val); // stack lvl7
char check_insert_subgrid4(char **grid, char val); // stack lvl7
char check_insert_subgrid5(char **grid, char val); // stack lvl7
char check_insert_subgrid6(char **grid, char val); // stack lvl7
char check_insert_subgrid7(char **grid, char val); // stack lvl7
char check_insert_subgrid8(char **grid, char val); // stack lvl7
char check_insert_subgrid9(char **grid, char val); // stack lvl7
//########################################################
//#########################play###############################

void play_game(Game *game); // stack lvl2
void navigate(char **grid); // stack lvl3
void display_grid(char **grid); // stack lvl4

char check_win(char **grid); // stack lvl3
char check_rows(char **grid); // stack lvl4
char check_cols(char **grid); // stack lvl4
char check_subgrids(char **grid); // stack lvl4


#endif // SUDOKU_H
