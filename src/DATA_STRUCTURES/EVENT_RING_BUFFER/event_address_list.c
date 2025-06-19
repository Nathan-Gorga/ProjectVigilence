#include "event_ring_buffer.h"


Node * initNode(void){
    Node * temp_node = (Node*)malloc(sizeof(Node));
    temp_node->event_start = NULL;
    temp_node->event_stop = NULL;
    temp_node->next = NULL;
    return temp_node;
}

// TODO : add linkToEvent function (think about the linking process)

void freeNode(Node * node){
    free(node);
}
