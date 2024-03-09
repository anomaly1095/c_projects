#include "sudoku.h"



int main(int argc, char **argv){
    if (argc == 2 && (argv[1] == "--h" || argv[1] == "help")){
        help();
    }else if (argc == 2 && (argv[1] != "--h" && argv[1] != "help")){
        return 01;
    }
    start_game();
    return 0;
}


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
}


char **initialize_Grid(){
    char **grid = (char**)malloc(sizeof(char*) * 9); // initialize rows
    for (size_t i = 0; i < 9; i++)
        *(grid+i) = (char*)malloc(sizeof(char) * 9); // initialize cols
    return grid;
}

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

void fill_lvl1(char **grid){
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
}

void fill_lvl2(char **grid){

}

void fill_lvl3(char **grid){

}

void fill_lvl4(char **grid){

}

void fill_lvl5(char **grid){

}
