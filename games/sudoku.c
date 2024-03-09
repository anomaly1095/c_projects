#include "sudoku.h"



int main(int argc, char **argv){
    if (argc == 2 && (argv[1] == "--h" || argv[1] == "help")){
        help();
    }else if (argc >= 2 && (argv[1] != "--h" && argv[1] != "help")){
        fprintf(stderr, "Invalid args\n");
        return 01;
    }
    Game *game = start_game();
    play_game(game);
    return 0;
}

void help(){
    
}

//#########################PLAY###############################

void play_game(Game *game){
    struct timespec delay;
    delay.tv_sec = 0;
    delay.tv_nsec = 200000000; // 500,000,000 nanoseconds = 0.5 seconds
    nanosleep(&delay, NULL);
    while (!check_win(game->grid)){
        navigate(game->grid);
    }

    system("clear");
    char *win_msg = (char*)malloc(sizeof(char) * 100), j = 0;
    sprintf(win_msg, "\n\n\t\tCongratulations %s you just beat a level %c Sudoku!!!\n", game->player_name, game->lvl);
    
    for (size_t i = 0; i < 0x10; i++){
        while (win_msg[j] != 00){
            fputc(win_msg[j], stdout);
            nanosleep(&delay, NULL);
        }system("clear");
    }
    free(win_msg);
}

void navigate(char **grid){
    
}

void display_grid(char **grid){
    for (size_t i = 0; i < RANGE; i++){
        printf("\t\t#####################################\n");
        printf("\t\t");
        for (size_t j = 0; j < RANGE; j++){
            printf("# %c", grid[i][j]);
        }printf(" #\n");
    }
    printf("\t\t#####################################\n");
}

char check_win(char **grid){
    if (!check_rows(grid) || !check_cols(grid) || !check_rows(grid)){
        return 00;
    }
    return 01;
}

char check_rows(char **grid){
    char *found, val;
    for (size_t i = 00; i < RANGE; i++){ // iterate over rows
        found = (char*)calloc(sizeof(char), RANGE);
        for (size_t j = 00; j < RANGE; j++){ // iterate over the row
            val = (grid[i][j] ^ _MASK) -1; // convert char to int and sub1 for index alignement
            if (found[val] == 01){
                free(found);
                return 00;
            }
            found[val]++;
        }
        free(found);
    }
    return 01;
}

char check_cols(char **grid){
    char *found, val;
    for (size_t i = 00; i < RANGE; i++){ // iterate over cols
        found = (char*)calloc(sizeof(char), RANGE);
        for (size_t j = 00; j < RANGE; j++){ // iterate over the col
            val = (grid[j][i] ^ _MASK) -1; // convert char to int and sub1 for index alignement
            if (found[val] == 01){
                free(found);
                return 00;
            }
            found[val]++;
        }
        free(found);
    }
    return 01;
}

char check_subgrids(char **grid){
    char res = 01;
    res &= check_subgrid1(grid);
    res &= check_subgrid2(grid);
    res &= check_subgrid3(grid);
    res &= check_subgrid4(grid);
    res &= check_subgrid5(grid);
    res &= check_subgrid6(grid);
    res &= check_subgrid7(grid);
    res &= check_subgrid8(grid);
    res &= check_subgrid9(grid);
    return res;
}

char check_subgrid1(char **grid){
    char i, j, *found, val;

    found = (char*)calloc(sizeof(char), RANGE);
    for (i = 00; i < 03; i++){
        for (j = 00; j < 03; j++){
            val = (grid[i][j] ^ _MASK) -1; // convert char to int and sub1 for index alignement
            if (found[val] == 01){
                free(found);
                return 00;
            }
            found[val]++;
        }
    }free(found);
    return 01;
}

char check_subgrid2(char **grid){
    char i, j, *found, val;
    
    found = (char*)calloc(sizeof(char), RANGE);
    for (i = 00; i < 03; i++){
        for (j = 03; j < 06; j++){
            val = (grid[i][j] ^ _MASK) -1; // convert char to int and sub1 for index alignement
            if (found[val] == 01){
                free(found);
                return 00;
            }
            found[val]++;
        }
    }free(found);
    return 01;
}

char check_subgrid3(char **grid){
    char i, j, *found, val;
    
    found = (char*)calloc(sizeof(char), RANGE);
    for (i = 00; i < 03; i++){
        for (j = 06; j < RANGE; j++){
            val = (grid[i][j] ^ _MASK) -1; // convert char to int and sub1 for index alignement
            if (found[val] == 01){
                free(found);
                return 00;
            }
            found[val]++;
        }
    }free(found);
    return 01;
}

char check_subgrid4(char **grid){
    char i, j, *found, val;
    
    found = (char*)calloc(sizeof(char), RANGE);
    for (i = 03; i < 06; i++){
        for (j = 00; j < 03; j++){
            val = (grid[i][j] ^ _MASK) -1; // convert char to int and sub1 for index alignement
            if (found[val] == 01){
                free(found);
                return 00;
            }
            found[val]++;
        }
    }free(found);
    return 01;
}

char check_subgrid5(char **grid){
    char i, j, *found, val;
    
    found = (char*)calloc(sizeof(char), RANGE);
    for (i = 03; i < 06; i++){
        for (j = 03; j < 06; j++){
            val = (grid[i][j] ^ _MASK) -1; // convert char to int and sub1 for index alignement
            if (found[val] == 01){
                free(found);
                return 00;
            }
            found[val]++;
        }
    }free(found);
    return 01;
}

char check_subgrid6(char **grid){
    char i, j, *found, val;
    
    found = (char*)calloc(sizeof(char), RANGE);
    for (i = 03; i < 06; i++){
        for (j = 06; j < RANGE; j++){
            val = (grid[i][j] ^ _MASK) -1; // convert char to int and sub1 for index alignement
            if (found[val] == 01){
                free(found);
                return 00;
            }
            found[val]++;
        }
    }free(found);
    return 01;
}

char check_subgrid7(char **grid){
    char i, j, *found, val;
    
    found = (char*)calloc(sizeof(char), RANGE);
    for (i = 06; i < RANGE; i++){
        for (j = 00; j < 03; j++){
            val = (grid[i][j] ^ _MASK) -1; // convert char to int and sub1 for index alignement
            if (found[val] == 01){
                free(found);
                return 00;
            }
            found[val]++;
        }
    }free(found);
    return 01;
}

char check_subgrid8(char **grid){
    char i, j, *found, val;
    
    found = (char*)calloc(sizeof(char), RANGE);
    for (i = 06; i < RANGE; i++){
        for (j = 03; j < 06; j++){
            val = (grid[i][j] ^ _MASK) -1; // convert char to int and sub1 for index alignement
            if (found[val] == 01){
                free(found);
                return 00;
            }
            found[val]++;
        }
    }free(found);
    return 01;
}

char check_subgrid9(char **grid){
    char i, j, *found, val;
    
    found = (char*)calloc(sizeof(char), RANGE);
    for (i = 06; i < RANGE; i++){
        for (j = 06; j < RANGE; j++){
            val = (grid[i][j] ^ _MASK) -1; // convert char to int and sub1 for index alignement
            if (found[val] == 01){
                free(found);
                return 00;
            }
            found[val]++;
        }
    }free(found);
    return 01;
}



//#########################SETUP###############################
// initialize a game
Game *start_game(){
    Game *game = (Game*)malloc(sizeof(Game));
    game->player_name = (char*)malloc(sizeof(char) * LEN_NAME);
    
    printf("Enter Your name: ");
    fgets(game->player_name, LEN_NAME, stdin);
    game->grid = initialize_Grid(); 
    printf("Enter the difficulty level(1/2/3/4/5): ");
    game->lvl = fgetc(stdin);
    if (game->lvl != ONE && game->lvl != TWO && game->lvl != THREE && game->lvl != FOUR && game->lvl != FIVE){
        game->lvl = fgetc(stdin);
    }
    fill_grid(game);
    return game;
}

// allocate memory for grid
char **initialize_Grid(){
    char **grid = (char**)malloc(sizeof(char*) * RANGE); // initialize rows
    for (size_t i = 00; i < RANGE; i++)
        *(grid+i) = (char*)malloc(sizeof(char) * RANGE); // initialize cols
    return grid;
}

// fill memory with random values according to difficulty
void fill_grid(Game *game){
    unsigned int seed = (unsigned int)time(NULL);
    srand(seed);
    switch (game->lvl){
    case ONE:       fill_lvl1(game->grid);      break;
    case TWO:       fill_lvl2(game->grid);      break;
    case THREE:     fill_lvl3(game->grid);      break;
    case FOUR:      fill_lvl4(game->grid);      break;
    case FIVE:      fill_lvl5(game->grid);      break;
    }
}

// (40) 4 of each + 4 others
void fill_lvl1(char **grid){
    char val, row, col, i;
    char others[REST_REP_L1] = {ONE, TWO, THREE, FOUR};
    while (nodes[0].rep != MAX_REP_L1 || nodes[1].rep != MAX_REP_L1
        || nodes[2].rep != MAX_REP_L1 || nodes[3].rep != MAX_REP_L1
        || nodes[4].rep != MAX_REP_L1 || nodes[5].rep != MAX_REP_L1
        || nodes[6].rep != MAX_REP_L1 || nodes[7].rep != MAX_REP_L1
        || nodes[8].rep != MAX_REP_L1){
        
        val = (char)(rand() % RANGE + MIN_VAL);
        row = (char)(rand() % RANGE + MIN_INDEX); 
        col = (char)(rand() % RANGE + MIN_INDEX);
        if (nodes[(val-1) ^ _MASK].rep != MAX_REP_L1 && can_insert(grid, val, row, col)){
            grid[row][col] = val;
            nodes[val ^ _MASK].rep++;
        }
    }
    // inserting eccess values
    for (i = 0; i < REST_REP_L1; i++){
        row = (char)(rand() % RANGE + MIN_INDEX); 
        col = (char)(rand() % RANGE + MIN_INDEX);
        while (!can_insert(grid, others[i], row, col)){
            row = (char)(rand() % RANGE + MIN_INDEX); 
            col = (char)(rand() % RANGE + MIN_INDEX);
        }
        grid[row][col];
        nodes[(others[i]-1) ^ _MASK].rep++;
    }
}

// (35) 3 of each + 8 others
void fill_lvl2(char **grid){
    char val, row, col, i;
    char others[REST_REP_L2] = {ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT};
    while (nodes[00].rep != MAX_REP_L2 || nodes[01].rep != MAX_REP_L2
        || nodes[02].rep != MAX_REP_L2 || nodes[03].rep != MAX_REP_L2
        || nodes[04].rep != MAX_REP_L2 || nodes[05].rep != MAX_REP_L2
        || nodes[06].rep != MAX_REP_L2 || nodes[07].rep != MAX_REP_L2
        || nodes[010].rep != MAX_REP_L2){
        
        val = (char)(rand() % RANGE + MIN_VAL);
        row = (char)(rand() % RANGE + MIN_INDEX); 
        col = (char)(rand() % RANGE + MIN_INDEX);
        if (nodes[(val-01) ^ _MASK].rep != MAX_REP_L2 && can_insert(grid, val, row, col)){
            grid[row][col] = val;
            nodes[val ^ _MASK].rep++;
        }
    }
    for (i = 00; i < REST_REP_L2; i++){
        row = (char)(rand() % RANGE + MIN_INDEX); 
        col = (char)(rand() % RANGE + MIN_INDEX);
        while (!can_insert(grid, others[i], row, col)){
            row = (char)(rand() % RANGE + MIN_INDEX); 
            col = (char)(rand() % RANGE + MIN_INDEX);
        }
        grid[row][col];
        nodes[(others[i]-1) ^ _MASK].rep++;
    }
}

// (30) 3 of each + 3 others
void fill_lvl3(char **grid){
    char val, row, col, i;
    char others[REST_REP_L3] = {ONE, TWO, THREE};
    while (nodes[00].rep != MAX_REP_L3 || nodes[01].rep != MAX_REP_L3
        || nodes[02].rep != MAX_REP_L3 || nodes[03].rep != MAX_REP_L3
        || nodes[04].rep != MAX_REP_L3 || nodes[05].rep != MAX_REP_L3
        || nodes[06].rep != MAX_REP_L3 || nodes[07].rep != MAX_REP_L3
        || nodes[010].rep != MAX_REP_L3){
        
        val = (char)(rand() % RANGE + MIN_VAL);
        row = (char)(rand() % RANGE + MIN_INDEX); 
        col = (char)(rand() % RANGE + MIN_INDEX);
        if (nodes[(val-01) ^ _MASK].rep != MAX_REP_L3 && can_insert(grid, val, row, col)){
            grid[row][col] = val;
            nodes[val ^ _MASK].rep++;
        }
    }
    for (i = 00; i < REST_REP_L3; i++){
        row = (char)(rand() % RANGE + MIN_INDEX); 
        col = (char)(rand() % RANGE + MIN_INDEX);
        while (!can_insert(grid, others[i], row, col)){
            row = (char)(rand() % RANGE + MIN_INDEX); 
            col = (char)(rand() % RANGE + MIN_INDEX);
        }
        grid[row][col];
        nodes[(others[i]-1) ^ _MASK].rep++;
    }
}

// (25) 2 of each + 7 others
void fill_lvl4(char **grid){
    char val, row, col, i;
    char rest[REST_REP_L5] = {ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT};
    while (nodes[00].rep != MAX_REP_L4 || nodes[01].rep != MAX_REP_L4
        || nodes[02].rep != MAX_REP_L4 || nodes[03].rep != MAX_REP_L4
        || nodes[04].rep != MAX_REP_L4 || nodes[05].rep != MAX_REP_L4
        || nodes[06].rep != MAX_REP_L4 || nodes[07].rep != MAX_REP_L4
        || nodes[010].rep != MAX_REP_L4){
        
        val = (char)(rand() % RANGE + MIN_VAL);
        row = (char)(rand() % RANGE + MIN_INDEX); 
        col = (char)(rand() % RANGE + MIN_INDEX);
        if (nodes[(val-01) ^ _MASK].rep != MAX_REP_L4 && can_insert(grid, val, row, col)){
            grid[row][col] = val;
            nodes[val ^ _MASK].rep++;
        }
    }
    for (i = 00; i < REST_REP_L4; i++){
        row = (char)(rand() % RANGE + MIN_INDEX); 
        col = (char)(rand() % RANGE + MIN_INDEX);
        while (!can_insert(grid, rest[i], row, col)){
            row = (char)(rand() % RANGE + MIN_INDEX); 
            col = (char)(rand() % RANGE + MIN_INDEX);
        }
        grid[row][col];
        nodes[(rest[i]-01) ^ _MASK].rep++;
    }
}

// (20) 2 of each + 2 others
void fill_lvl5(char **grid){
    char val, row, col, i;
    char others[REST_REP_L5] = {ONE, TWO};
    while (nodes[00].rep != MAX_REP_L5 || nodes[01].rep != MAX_REP_L5
        || nodes[02].rep != MAX_REP_L5 || nodes[03].rep != MAX_REP_L5
        || nodes[04].rep != MAX_REP_L5 || nodes[05].rep != MAX_REP_L5
        || nodes[06].rep != MAX_REP_L5 || nodes[07].rep != MAX_REP_L5
        || nodes[010].rep != MAX_REP_L5){
        
        val = (char)(rand() % RANGE + MIN_VAL);
        row = (char)(rand() % RANGE + MIN_INDEX); 
        col = (char)(rand() % RANGE + MIN_INDEX);
        if (nodes[(val-01) ^ _MASK].rep != MAX_REP_L5 && can_insert(grid, val, row, col)){
            grid[row][col] = val;
            nodes[val ^ _MASK].rep++;
        }
    }
    for (i = 00; i < REST_REP_L5; i++){
        row = (char)(rand() % RANGE + MIN_INDEX); 
        col = (char)(rand() % RANGE + MIN_INDEX);
        while (!can_insert(grid, others[i], row, col)){
            row = (char)(rand() % RANGE + MIN_INDEX); 
            col = (char)(rand() % RANGE + MIN_INDEX);
        }
        grid[row][col];
        nodes[(others[i]-01) ^ _MASK].rep++;
    }
}

char can_insert(char **grid, char val, char row, char col){
    if (check_row(grid, val, row) && check_col(grid, val, col) && check_subgrid(grid, val, row, col)){
        return 01;
    }
    return 00;
}

char check_insert_row(char **grid, char val, char row){
    for (size_t i = 00; i < RANGE; i++){
        if (grid[row][i] == val)
            return 00;
    }
    return 01;
}

char check_insert_col(char **grid, char val, char col){
    for (size_t i = 00; i < RANGE; i++){
        if (grid[i][col] == val)
            return 00;
    }
    return 01;
}

char check_insert_subgrid(char **grid, char val, char row, char col){
    if (row < 03){ 
        if (col < 03){
            return check_insert_subgrid1(grid, val);
        }else if (col > 02 && col < 06){
            return check_insert_subgrid2(grid, val);
        }else{
            return check_insert_subgrid3(grid, val);
        }
    
    }else if (row > 02 && row < 06){
        if (col < 03){
            return check_insert_subgrid4(grid, val);
        }else if (col > 02 && col < 06){
            return check_insert_subgrid5(grid, val);
        }else{
            return check_insert_subgrid6(grid, val);
        }
    
    }else{
        if (col < 03){
            return check_insert_subgrid7(grid, val);
        }else if (col > 02 && col < 06){
            return check_insert_subgrid8(grid, val);
        }else{
            return check_insert_subgrid9(grid, val);
        }
    }
}

char check_insert_subgrid1(char **grid, char val){
    char i, j;
    for (i = 00; i < 03; i++){
        for (j = 00; j < 03; j++){
            if (grid[i][j] == val)
                return 00;
        }
    }
    return 01;
}

char check_insert_subgrid2(char **grid, char val){
    char i, j;
    for (i = 00; i < 03; i++){
        for (j = 03; j < 06; j++){
            if (grid[i][j] == val)
                return 00;
        }
    }
    return 01;
}

char check_insert_subgrid3(char **grid, char val){
    char i, j;
    for (i = 00; i < 03; i++){
        for (j = 06; j < RANGE; j++){
            if (grid[i][j] == val)
                return 00;
        }
    }
    return 01;
}

char check_insert_subgrid4(char **grid, char val){
    char i, j;
    for (i = 03; i < 06; i++){
        for (j = 00; j < 03; j++){
            if (grid[i][j] == val)
                return 00;
        }
    }
    return 01;
}

char check_insert_subgrid5(char **grid, char val){
    char i, j;
    for (i = 03; i < 06; i++){
        for (j = 03; j < 06; j++){
            if (grid[i][j] == val)
                return 00;
        }
    }
}

char check_insert_subgrid6(char **grid, char val){
    char i, j;
    for (i = 03; i < 06; i++){
        for (j = 06; j < RANGE; j++){
            if (grid[i][j] == val)
                return 00;
        }
    }
    return 01;
}

char check_insert_subgrid7(char **grid, char val){
    char i, j;
    for (i = 06; i < RANGE; i++){
        for (j = 00; j < 03; j++){
            if (grid[i][j] == val)
                return 00;
        }
    }
    return 01;
}

char check_insert_subgrid8(char **grid, char val){
    char i, j;
    for (i = 06; i < RANGE; i++){
        for (j = 03; j < 06; j++){
            if (grid[i][j] == val)
                return 00;
        }
    }
    return 01;
}

char check_insert_subgrid9(char **grid, char val){
    char i, j;
    for (i = 06; i < RANGE; i++){
        for (j = 06; j < RANGE; j++){
            if (grid[i][j] == val)
                return 00;
        }
    }
    return 01;
}

