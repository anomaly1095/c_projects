#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

//###################################################

/// @brief Player struct 
/// @param (char *) name of the player
/// @param (char) what the player was assigned (X or O)
/// @param (int) player's score 
typedef struct Player{
    char *name;
    char plays;  // x or o
    int score; 
}Player;

/// @brief Entry point
/// @return 00 success else 01
int main();

/// @brief initiate the player's arguments
/// @param p1 (Player *) 
/// @param p2 (Player *)
void start(Player *p1, Player *p2);

/// @brief main function contains a loop for each game
/// @param grid (char **) game's grid
/// @param p1 (Player *)
/// @param p2 (Player *)
void play(char **grid, Player *p1, Player *p2);

/// @brief 
/// @param grid (char **) game's grid
void initialize_grid(char **grid);

/// @brief checks if a winner is found
/// @param grid (char **) game's grid
/// @param p1 (Player *)
/// @param p2 (Player *)
/// @return (char)
char winner(char **grid, Player *p1, Player *p2);

/// @brief prints the 3x3 grid with it's contents
/// @param grid (char **) game's grid
void print_grid(char **grid);

/// @brief gets the input from stdin without having to press enter
/// @return (char) returns the catched char
char get_char_input();

/// @brief inserts X or O in the grid
/// @param grid (char **) game's grid
/// @param pos (char) position of insertion selected by user
/// @param element (char) X or O based on what the current user is playing 
/// @return (char) 00 if impossible insertion 01 if success
char insert_item(char **grid, char pos, char element);

/// @brief prints a message to the winner winner 
/// @param grid (char **) game's grid
/// @param y (char) y axes-> row
/// @param x (char) x axes-> col
/// @param p1 (Player *)
/// @param p2 (Player *)
void print_winner(char **grid, char y, char x, Player *p1, Player *p2);

/// @brief checks if grid is full
/// @param grid (char **) game's grid
/// @return (char) return 0 if full 01 if there's more space
char check_full(char **grid);

/// @brief frees the memory allocated for each player from the heap
/// @param p1 (Player *)
/// @param p2 (Player *)
void free_players(Player *p1, Player *p2);

/// @brief frees each of the 3 rows (char*) the frees the (char**) from the heap
/// @param grid (char **) game's grid
void free_grid(char **grid);

//###################################################

int main(){
    Player *p1 = (Player*)malloc(sizeof(Player));
    Player *p2 = (Player*)malloc(sizeof(Player));
    char **grid = (char**)malloc(sizeof(char*) * 03);

    start(p1, p2);
    getc(stdin);
    play(grid, p1, p2);

    free_players(p1, p2);
    free_grid(grid);
    free(grid);
    return 00;
}



void start(Player *p1, Player *p2){
    p1->name = (char*)malloc(sizeof(char) * 20);
    p2->name = (char*)malloc(sizeof(char) * 20);
    printf("Player 1 enter your name (will start with X): ");
    scanf("%s", p1->name);
    p1->score = 00;
    p1->plays = 0x58; // X
    printf("Player 2 enter your name (will start with O): ");
    scanf("%s", p2->name);
    p2->plays = 0x4F; // O
    p2->score = 00;
}


void play(char **grid, Player *p1, Player *p2){
    char keyboard_in = 00;
    Player *starts = p1, *current;
    while (1){ //new game
        initialize_grid(grid);
        current = starts;

        while (!winner(grid, p1, p2) && check_full(grid)){//same game
            print_grid(grid);
            printf("\t\t%s's turn: \n>>> ", current->name);

            fflush(stdout);
            keyboard_in = get_char_input();
            if (keyboard_in == 0x71)
                return;
            
            if (!insert_item(grid, keyboard_in, current->plays)){
                system("clear");
                printf("\t\tInvalid position: %c\n", keyboard_in);
                continue;
            }
            
            if (current == p1) {current = p2;}
            else {current = p1;}
            
            system("clear");
        }
        
        if (p1->plays == 0x4F) {
            p1->plays = 0x58;
            p2->plays = 0x4F;
        }else{
            p1->plays = 0x4F;
            p2->plays = 0x58;
        }
        
        if (starts == p1){
            starts = p2;
        }else{
            starts = p1;
        }
    }
}


char insert_item(char **grid, char pos, char element){
    if (pos != 0x31 && pos != 0x32 && pos != 0x33 && pos != 0x34 && pos != 0x35 &&
        pos != 0x36 && pos != 0x37 && pos != 0x38 && pos != 0x39){
        return 00;
    }
    char x = 0x31;
    for (char i = 0; i < 3; i++){
        for (char j = 0; j < 3; j++){
            if (x == pos){
                if ( *(*(grid+i)+j) == 0x5 || *(*(grid+i)+j) == 0x58 ){
                    return 00;
                }
                if ( *(*(grid+i)+j) != 0x4F && *(*(grid+i)+j) != 0x58 ){
                    *(*(grid+i)+j) = element;
                    return 01;
                }
            }
            x++;
        }
    }
}


void initialize_grid(char **grid){
    char j = 01, t;
    for (char i = 00; i < 03; i++){
        *(grid+i) = (char*)calloc(sizeof(char), 3);
        for (t = 00; t < 03; t++){
            *(*(grid+i)+t) = 0x30 + j;
            j++;
        }
    }
}


void print_grid(char **grid){
    printf("\t\t-------------\n");
    printf("\t\t-Tik-Tak-Toe-\n");
    printf("\t\t-------------\n");
    printf("\t\t#############\n");
    printf("\t\t# %c # %c # %c #\n", *(*(grid+0)+0), *(*(grid+0)+1), *(*(grid+0)+2));
    printf("\t\t#############\n");
    printf("\t\t# %c # %c # %c #\n", *(*(grid+1)+0), *(*(grid+1)+1), *(*(grid+1)+2));
    printf("\t\t#############\n");
    printf("\t\t# %c # %c # %c #\n", *(*(grid+2)+0), *(*(grid+2)+1), *(*(grid+2)+2));
    printf("\t\t#############\n");
}


char get_char_input() {
    char c;
    struct termios oldt, newt;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return c;
}


void print_winner(char **grid, char y, char x, Player *p1, Player *p2){
    if (*(grid+y)[x] == p1->plays){
        printf("\nCongratulations %s for the win!\n", p1->name);
        p1->score++;
        system("sleep 3");
        return;
    }
    printf("\nCongratulations %s for the win!\n", p2->name);
    p2->score++;
    system("sleep 3");
    system("clear");
}


char winner(char **grid, Player *p1, Player *p2) {
    if (*(*(grid + 0) + 0) == *(*(grid + 0) + 1) && *(*(grid + 0) + 0) == *(*(grid + 0) + 2)) { // row 1
        print_winner(grid, 0, 0, p1, p2);
        return 1;
    } else if (*(*(grid + 1) + 0) == *(*(grid + 1) + 1) && *(*(grid + 1) + 0) == *(*(grid + 1) + 2)) { // row 2
        print_winner(grid, 1, 0, p1, p2);
        return 1;
    } else if (*(*(grid + 2) + 0) == *(*(grid + 2) + 1) && *(*(grid + 2) + 0) == *(*(grid + 2) + 2)) { // row 3
        print_winner(grid, 2, 0, p1, p2);
        return 1;
    } else if (*(*(grid + 0) + 0) == *(*(grid + 1) + 0) && *(*(grid + 0) + 0) == *(*(grid + 2) + 0)) { // col 1
        print_winner(grid, 0, 0, p1, p2);
        return 1;
    } else if (*(*(grid + 0) + 1) == *(*(grid + 1) + 1) && *(*(grid + 0) + 1) == *(*(grid + 2) + 1)) { // col 2
        print_winner(grid, 0, 1, p1, p2);
        return 1;
    } else if (*(*(grid + 0) + 2) == *(*(grid + 1) + 2) && *(*(grid + 0) + 2) == *(*(grid + 2) + 2)) { // col 3
        print_winner(grid, 0, 2, p1, p2);
        return 1;
    } else if (*(*(grid + 0) + 0) == *(*(grid + 1) + 1) && *(*(grid + 0) + 0) == *(*(grid + 2) + 2)) { // diagonal 1
        print_winner(grid, 0, 0, p1, p2);
        return 1;
    } else if (*(*(grid + 2) + 0) == *(*(grid + 1) + 1) && *(*(grid + 2) + 0) == *(*(grid + 0) + 2)) { // diagonal 2
        print_winner(grid, 2, 0, p1, p2);
        return 1;
    }
    return 0;
}


char check_full(char **grid){
    for (char i = 00; i < 03; i++){
        for (char j = 00; j < 03; j++){ // not full
            if (*(*(grid+i)+j) == 0x31 || *(*(grid+i)+j) == 0x32 || *(*(grid+i)+j) == 0x33 || *(*(grid+i)+j) == 0x34 || *(*(grid+i)+j) == 0x35 ||
                *(*(grid+i)+j) == 0x36 || *(*(grid+i)+j) == 0x37 || *(*(grid+i)+j) == 0x38 || *(*(grid+i)+j) == 0x39){
                return 01;
            } 
        }
    }
    return 00;
}


void free_players(Player *p1, Player *p2){
    free(p1->name);
    free(p1);
    free(p2->name);
    free(p2);
}


void free_grid(char **grid){
    for (char i = 0; i < 3; i++){
        free(*(grid+i));
    }
    free(grid);
}

//###################################################
