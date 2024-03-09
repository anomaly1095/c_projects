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
#define RANGE       0xA

Node nodes[9] = {
        [0].val = ONE, [0].val = 0x0,
        [1].val = TWO, [1].val = 0x0,
        [2].val = THREE, [2].val = 0x0,
        [3].val = FOUR, [3].val = 0x0,
        [4].val = FIVE, [4].val = 0x0,
        [5].val = SIX, [5].val = 0x0,
        [6].val = SEVEN, [6].val = 0x0,
        [7].val = EIGHT, [7].val = 0x0,
        [8].val = NINE, [8].val = 0x0,
    };

int main();
void help();
Game *start_game();
char **initialize_Grid();
void fill_grid(Game *game);
void fill_lvl1(char **grid);
void fill_lvl2(char **grid);
void fill_lvl3(char **grid);
void fill_lvl4(char **grid);
void fill_lvl5(char **grid);