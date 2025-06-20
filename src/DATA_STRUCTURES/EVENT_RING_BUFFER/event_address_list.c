#include "event_ring_buffer.h"


Node * initNode(void){

    Node * temp_node = (Node*)malloc(sizeof(Node));

    assert(temp_node != NULL);

    temp_node->start = -1;

    temp_node->stop = -1;

    temp_node->next = NULL;

    return temp_node;
}


void putBufferInRingBuffer(float * buffer, const int sizeBuffer){

    #ifdef ASSERT_MODE

    assert(buffer != NULL);

    #endif

    bool needsLoop = false; 

    if(event_ring_buffer->head + sizeBuffer >= EVENT_RING_BUFFER_SIZE){

        needsLoop = true;
    }

    if(!needsLoop){

        if(event_ring_buffer->head + sizeBuffer > event_ring_buffer->tail){
            perror(RED"ERROR : buffer overflow\n"RESET);
            return;
        }

        memcpy(event_ring_buffer->buffer + event_ring_buffer->head, buffer, sizeBuffer * sizeof(float));

        event_ring_buffer->head += sizeBuffer;

        return;
    }

    const int sizeFirstMemCPY = EVENT_RING_BUFFER_SIZE - event_ring_buffer->head;
    const int sizeSecondMemCPY = sizeBuffer - sizeFirstMemCPY;

    if(sizeSecondMemCPY > event_ring_buffer->tail){
        perror(RED"ERROR : buffer overflow\n"RESET);
        return;
    }

    memcpy(event_ring_buffer->buffer + event_ring_buffer->head, buffer, sizeFirstMemCPY * sizeof(float));
    memcpy(event_ring_buffer->buffer, buffer + sizeFirstMemCPY, sizeSecondMemCPY * sizeof(float));

    event_ring_buffer->head = sizeSecondMemCPY;
}


//internal buffer needs to be a linear buffer
void createEventNode(Node * event_node, float * internal_buffer, const int sizeInternalBuffer){

    #ifdef ASSERT_MODE
    
    assert(event_node != NULL);

    assert(internal_buffer != NULL);

    #endif

    event_node->start = event_ring_buffer->head;

    putBufferInRingBuffer(internal_buffer, sizeInternalBuffer);

    event_node->stop = event_ring_buffer->head;
}

 
void addNodeToList(Node * head, Node * node){

    #ifdef ASSERT_MODE

    assert(head != NULL);

    #endif

    Node * curr = head;

    while(curr->next != NULL){
        curr = curr->next;
    }

    curr->next = node;

}
void printNode(Node * node){
    
    if(node == NULL){
        printf("NULL\n");
        return;
    } 

    printf("%p -> ",node);
}

void printNodeList(Node * head){

    #ifdef ASSERT_MODE

    assert(head != NULL);

    #endif

    Node * curr = head->next;

    printf("HEAD -> ");

    while(curr != NULL){
        printNode(curr);
        curr = curr->next;
    }

    printNode(NULL);

}

void popNodeFromList(Node * head){

    #ifdef ASSERT_MODE

    assert(head != NULL);

    #endif

    if(head->next == NULL) return;
    
    Node * temp = head->next->next;

    freeNode(head->next);

    head->next = temp;

    event_ring_buffer->tail = head->next->start;

}

void freeNode(Node * node){

    #ifdef ASSERT_MODE

    assert(node != NULL);

    #endif

    free(node);
}

void freeList(Node * head){

    #ifdef ASSERT_MODE

    assert(head != NULL);

    #endif
 
    Node * temp = head->next;
 
    while(temp != NULL){
 
        Node * next = temp->next;
 
        freeNode(temp);
 
        temp = next;
    }

    free(head);
}