#include "_parse.h"


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

}

char check_buff(char *buff){
    
}

buffchar first_parse(char *buff, QueueNode **head){

}