#ifndef NODE_H
#define NODE_H
//EVENT ADDRESS LIST (IN RING BUFFER)
typedef struct address_node{
    int start;
    int stop;
    struct address_node * next;
}Node;



#endif
