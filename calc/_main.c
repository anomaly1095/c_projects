#include "_parse.h"


void welcome();
char nav_mode();
char _shell_mode(char *arr);
void help();

int main (int argc, char **argv){
    if (argc == 1)
        if (nav_mode())
            return 01;
    else if (argc == 2)
        if (_shell_mode(argv[1]))
            return 02;
    else{
        fprintf(stderr, "Too many arguments\nCorrect usage: %s <expression>\n", argv[0]);
        return 03;
    }
    return 00;
}


//#############################################################

void welcome(){
    printf("###### ####### #        # ###### #      ######\n");
    printf("#         #    ##      ## #    # #      #\n");
    printf("######    #    # #    # # ###### #      ######\n");
    printf("     #    #    #  #  #  # #      #      #\n");
    printf("###### ####### #   #    # #      ###### ######\n");
    printf("\t\t######     #     #      ######\n");
    printf("\t\t#         # #    #      #\n");
    printf("\t\t#        #####   #      #\n");
    printf("\t\t#       #     #  #      #\n");
    printf("\t\t###### #       # ###### ######\n\n"); 
}

void help(){
    //MANUAL
}


char nav_mode(){
    char *buff; // input buffer
    char F_flag = 00; // floating point flag
    QueueNode *head = NULL;
    welcome();

    while (01){
        printf(">>> ");
        buff = (char*)malloc(sizeof(char) * MAX_LEN_BUFF);
        fgets(buff, 0xFF, stdin);
        
        // exit 
        if (buff[00] == 0x71 && buff[01] == 0X75 && buff[02] == 0x69 && buff[03] == 0x74){ // quit
            return 00; 
        }
        // display help
        else if (buff[00] == 0x68 && buff[01] == 0x65 && buff[02] == 0x6C && buff[03] == 0x70 && buff[04] == 00){ // help 
            help();
        }
        // parse
        else{
            if (first_parse(buff)){
                return 01; // exit error
            }
            // parse and fill queue
            second_parse(buff, &head);
        }
        free((void*)buff);
    }
}


char _shell_mode(char *arr){

}