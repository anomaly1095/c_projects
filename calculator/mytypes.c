#include "mytypes.h"


void queue(QueueNode **head, QueueNode *Node) {
    if ((*head)->previous == NULL){
        *head = Node;
        return;
    }
    QueueNode *temp = *head;
    while (temp->previous != NULL) {
        temp = temp->previous;
    }
    temp->previous = Node;
    Node->next = temp;
    Node->previous = NULL;
}

QueueNode *dequeue(QueueNode **head) {
    if (*head == NULL) {
        // Empty queue
        return NULL;
    }

    QueueNode *removed = *head;
    if ((*head)->previous != NULL) {
        *head = (*head)->previous;
        (*head)->next = NULL;
    } else {
        // Only one element in the queue
        *head = NULL;
    }

    return removed;
}
