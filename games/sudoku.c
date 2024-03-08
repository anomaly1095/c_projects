#include "sudoku.h"

//####################################### emplementations


int main(){
    grid2D grid = initialize_grid();
    
    return 00;
}

//#######################################


grid2D **initialize_grid(){
    grid2D grid = (grid2D)malloc(sizeof(char*) * 0x9);
    for (char i = 00; i < 0x9; i++){
        grid[i] = (char*)malloc(sizeof(char) * 0x9);
    }
    printf("Choose the difficulty level\n");
    printf("1 for lvl1\n");
    printf("2 for lvl2\n");
    printf("3 for lvl3\n");
    printf("4 for lvl4\n");
    printf("5 for lvl5\n");
    char level = getc(stdin);
    while (level != ONE && level != TWO && level != THREE && level != FOUR && level != FIVE){
        printf("Invalid input: %c", level);
        level = getc(stdin);
    }
    srand((unsigned int)time(NULL)); // seed the RNG suite
    generate_vals_for_grid(grid, level);
}

void generate_vals_for_grid(grid2D grid, char level){
    if (level == ONE){//generate 20 numbers
        generate20(grid);
    }else if (level == TWO){//generate 35 numbers
        generate25(grid);
    }else if (level == THREE){//generate 30 numbers
        generate30(grid);
    }else if (level == FOUR){//generate 35 numbers
        generate35(grid);
    }else if (level == FIVE){//generate 40 numbers
        generate40(grid);
    }
}

void generate20(grid2D grid){
    char i = 00;
    char row, col, val;
    char repetitions[0x9] = {00, 00, 00, 00, 00, 00, 00, 00, 00};
    while (i < 0x14){
        row = (char)(rand() % RANGE_ROW_COL + MIN_ROW_COL) ^ CONVERSION_MASK; // generate the row index
        col = (char)(rand() % RANGE_ROW_COL + MIN_ROW_COL) ^ CONVERSION_MASK; // generate the col index
        val = (char)(rand() % RANGE_VAL     + MIN_VAL)     ^ CONVERSION_MASK; // generate the val to insert 
        if (repetitions[val-01] == 02){ // max number of the value reached
            continue;
        }else{
            if (check_cell(grid, row, col, val)){ // invalid position
                
            }
            insert_in_grid();
            repetitions[val-01]++;
            ++i;
        }
    }
}

void generate25(grid2D grid){

}

void generate30(grid2D grid){

}

void generate35(grid2D grid){

}

void generate40(grid2D grid){

}


char check_cell(grid2D grid, char y, char x, char val){
    char i;
    for (i = 0; i < RANGE_ROW_COL; i++){ // checking the row
        if (grid[y][i] == val){
            return 01;
        }
    }for (i = 0; i < RANGE_ROW_COL; i++){ // checking the col
        if (grid[i][x] == val){
            return 01;
        }
    }if (y > )
    {
        /* code */
    }
    
    return 00;
}

void insert_in_grid(grid2D grid, char row, char col, char val){
    
}

char check_rows(grid2D grid){

}

char check_cols(grid2D grid){

}

char check_subgrid_appartenance(grid2D grid, char row, char col, char val){
    if (val != 00){ // we check if a value can be inserted
        if (row <= 2 && col <= 2){ //top left
            
        }else if (row <= 2 && col >= 6){ // top right
            
        }else if (row >= 6 && col >= 6){ // bottom right
            
        }else if (row >= 6 && col <= 2){ // bottom left
            
        }else if (row <= 2 && col >= 3 && col <= 5){ // middle top
            
        }else if (row <= 5 && row >= 3 && col >= 6){ // middle right
            
        }else if (row >= 6 && col >= 3 && col <= 5){ // middle bottom
            
        }else if (row <= 5 && row >= 3 && col <= 2){ // middle left
            
        }else{ // center subgrid

        }
    }
}

char check_indiv_subgrid(grid2D grid, char subgrid_n, char val_to_check){
    switch (subgrid_n){
    case 0x1:
        
        break;
    case 0x2:
        
        break;
    case 0x3:
        
        break;
    case 0x4:
        
        break;
    case 0x5:
        
        break;
    case 0x6:
        
        break;
    case 0x7:
        
        break;
    case 0x8:
        
        break;
    case 0x9:
        
        break;
    }
}

char check_subgrids(grid2D grid){

}


void print_grid(grid2D grid){
    printf("\t\t**********************\n");
    printf("\t\t* %c * %c * %c * %c * %c * %c * %c * %c * %c *\n", grid[0][0], grid[0][1], grid[0][2], grid[0][3], grid[0][4], grid[0][5], grid[0][6], grid[0][7], grid[0][8]);
    printf("\t\t**********************\n");
    printf("\t\t* %c * %c * %c * %c * %c * %c * %c * %c * %c *\n", grid[1][0], grid[1][1], grid[1][2], grid[1][3], grid[1][4], grid[1][5], grid[1][6], grid[1][7], grid[1][8]);
    printf("\t\t**********************\n");
    printf("\t\t* %c * %c * %c * %c * %c * %c * %c * %c * %c *\n", grid[2][0], grid[2][1], grid[2][2], grid[2][3], grid[2][4], grid[2][5], grid[2][6], grid[2][7], grid[2][8]);
    printf("\t\t**********************\n");
    printf("\t\t* %c * %c * %c * %c * %c * %c * %c * %c * %c *\n", grid[3][0], grid[3][1], grid[3][2], grid[3][3], grid[3][4], grid[3][5], grid[3][6], grid[3][7], grid[3][8]);
    printf("\t\t**********************\n");
    printf("\t\t* %c * %c * %c * %c * %c * %c * %c * %c * %c *\n", grid[4][0], grid[4][1], grid[4][2], grid[4][3], grid[4][4], grid[4][5], grid[4][6], grid[4][7], grid[4][8]);
    printf("\t\t**********************\n");
    printf("\t\t* %c * %c * %c * %c * %c * %c * %c * %c * %c *\n", grid[5][0], grid[5][1], grid[5][2], grid[5][3], grid[5][4], grid[5][5], grid[5][6], grid[5][7], grid[5][8]);
    printf("\t\t**********************\n");
    printf("\t\t* %c * %c * %c * %c * %c * %c * %c * %c * %c *\n", grid[6][0], grid[6][1], grid[6][2], grid[6][3], grid[6][4], grid[6][5], grid[6][6], grid[6][7], grid[6][8]);
    printf("\t\t**********************\n");
    printf("\t\t* %c * %c * %c * %c * %c * %c * %c * %c * %c *\n", grid[7][0], grid[7][1], grid[7][2], grid[7][3], grid[7][4], grid[7][5], grid[7][6], grid[7][7], grid[7][8]);
    printf("\t\t**********************\n");
    printf("\t\t* %c * %c * %c * %c * %c * %c * %c * %c * %c *\n", grid[8][0], grid[8][1], grid[8][2], grid[8][3], grid[8][4], grid[8][5], grid[8][6], grid[8][7], grid[8][8]);
    printf("\t\t**********************\n");
}

