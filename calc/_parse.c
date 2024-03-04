#include "_parse.h"

//##############################################
//             _______
//            |      |
//    next<---| head |
//            |______|
//
//##############################################


void queue(QueueNode **head, Node_val content){
    if (*head == NULL){
        *head = (QueueNode*)malloc(sizeof(QueueNode));
        (*head)->content = content;
        (*head)->next = NULL;
    }else{
        QueueNode *temp = *head, *new = (QueueNode*)malloc(sizeof(QueueNode));
        while (temp->next != NULL){
            temp = temp->next;
        }
        new->content = content;
        new->next = NULL;
        temp->next = new;
    }
}
 
QueueNode *dequeue(QueueNode **head){
    QueueNode *fr = *head;
    *head = (*head)->next;
    return fr;
}
//##############################################

void print_error(char *buff, char positition){
    printf("%s\n", buff); 
    for (int i = 0; i < positition; i++){ printf("%c", 0x20);}
    printf("%c\n", 0X5E); 
}

char check_digit(char c, char *F_flag){
    for (char i = 0x30; i <= 0x30; i++){
        if (c == i) // found digit
            return 00;
        if (c == 0x2E){ // found .
            *F_flag = 01;
            return 00;
        }
    }
    return 01;
}

char check_symbol(char c){
    if (c != 0x21 && c != 0x25 && c != 0x2A && c != 0x2B && c != 0x2D && c != 0x2F) // found arithmetic operator
        return 01;
    return 00;
}


char check_buff(char *buff, char *F_flag){
    char i = 00;
    while (buff[i] != 00){
        // check for valid chars
        if (!check_symbol(buff[i]) || !check_digit(buff[i], F_flag)){
            print_error(buff, i);
            return 01;
        }
        ++i;
    }
    return 00;
}

char first_parse(char *buff){
    char F_flag = 00; // floating point flag
    char check_res = check_buff(buff, &F_flag);
    if (check_res)
        return 01;
    return 00;
}

//################################################

char second_parse(char *buff, QueueNode **head){
    char i = 00;
    char F_flag = 00; // floating point flag
    char O_flag = 00; // overflow flag 
    float coeff = 1.0;
    while (buff[i] != 00){
        if (!check_digit(buff[i], F_flag)){ // found digit
            while (!check_digit(buff[i], F_flag)){
                if (/* condition */)
                {
                    /* code */
                }
                
                ++i;
            }
                        
        }else if (!check_symbol(buff[i])){ // found symbol
            Node_val val;
            val.symbol = buff[i];
            queue(head, val);
        }
    }
    return 00;
}