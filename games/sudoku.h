#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//####################################### definitions

#if !defined(SUDOKU_H)
#define SUDOKU_H
#define grid2D char**

#define MIN_ROW_COL 0x30
#define MAX_ROW_COL 0x38
#define RANGE_ROW_COL 0x9 // MAX-MIN+1
#define MIN_VAL 0x31
#define MAX_VAL 0x39
#define RANGE_VAL 0x9
#define CONVERSION_MASK 0b110000
#define ZERO 0x30
#define ONE 0x31
#define TWO 0x32
#define THREE 0x33
#define FOUR 0x34
#define FIVE 0x35
#define SIX 0x36
#define SEVEN 0x37
#define EIGHT 0x38
#define NINE 0x39
 
#define LVL1 0X14
#define LVL2 0x19
#define LVL3 0x1E
#define LVL4 0x23
#define LVL5 0x28

// initialize grid will need an algo for random generations
grid2D **initialize_grid();
void generate_vals_for_grid(grid2D grid, char level);
void generate20(grid2D grid);
void generate25(grid2D grid);
void generate30(grid2D grid);
void generate35(grid2D grid);
void generate40(grid2D grid);
void insert_in_grid(grid2D grid, char row, char col, char val);

void print_grid(grid2D grid);
void play(grid2D grid);
void print_grid(grid2D grid);
char check_cell(grid2D grid, char row, char col, char val);
char check_rows(grid2D grid);
char check_cols(grid2D grid);
char check_indiv_subgrid(grid2D grid, char row, char col, char val);
char check_subgrids(grid2D grid);
char check_win(grid2D grid);

#endif // SUDOKU_H
