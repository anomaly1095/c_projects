#include "sparsing.h"




/*



*/

//##############################################
void welcome();
void help();
void navigation();
//##############################################


_int8 main(_int8 argc, char **argv){
    switch (argc){
    case 1:
        goto shell_mode;
        break;
    case 2:
        goto one_line_mode;
        break;
    default:
        goto too_many_arguments;
        break;
    }
    
    one_line_mode:
        get_buffer(argv[1]);
        return 0;
    shell_mode:
        navigation();
        return 0;
    too_many_arguments:
        printf("Invalid arguments: ");
        for (int i = 2; i < argc; i++){
            printf("%s ", argv[i]);
        }
        printf("\n");
        return -1;
    return 0x0;
}


void navigation(){
    welcome();
    char *buffer = (char*)calloc(sizeof(char), 255);
    _int8 res;
    while (0x1){
        printf("---> ");
        fgets(buffer, 255, stdin);
        res = get_buffer(buffer);
        switch (res){
        case 0x0:
            break;
        case 0x1:
            goto _exit;
            break;
        case 0x2:
            help();
        case 0x3:
            continue;
        default:
            break;
        }
    }
    _exit:
        return;
}





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
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
}