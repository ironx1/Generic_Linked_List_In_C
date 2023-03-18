#include <stdlib.h>
#include <stdio.h>

#ifndef GENERICLINKEDLIST_LIBRARY_H
#define GENERICLINKEDLIST_LIBRARY_H
typedef char *string;

#define addMacro(type) Node* add_##type(Node* node, type* data){ \
    if(node==NULL){                                              \
        node = (Node*)malloc(sizeof(Node));                      \
        node->data = data;                                       \
        node->next = NULL;                                       \
        return node;                                             \
    }                                                            \
    Node* iter = node;                                           \
    while(iter->next!=NULL){                                     \
    iter = iter->next;                                           \
    }                                                            \
    iter->next = (Node*)malloc(sizeof(Node));                    \
    iter->next->data = data;                                     \
    iter->next->next = NULL;                                     \
    return node;                                                 \
}
#define printMacro(format, type) void print_##type(Node* node){ \
    if(node==NULL){                                             \
        return;                                                 \
    }                                                           \
    Node* iter = node;                                          \
    while(iter!=NULL){                                          \
        type* temp = (type*)iter->data;                         \
        printf("%"#format" ",*temp);                            \
        iter = iter->next;                                      \
    }                                                           \
}
typedef struct linkedList {
    void *data;
    struct linkedList *next;
    struct linkedList *(*add)(struct linkedList *node, void *data);
    void (*printNode)(struct linkedList *node);
} Node;

addMacro(int)

printMacro(d, int)

addMacro(string)

printMacro(s, string)

#define addToList(node, val) _Generic((val),    \
int*:add_int,                                   \
string*:add_string                              \
)(node, val)

#define printNodes(node, val) _Generic((val),   \
int:print_int,                                  \
string:print_string\
)(node)

#define new(type) Node* newNode_##type(void* data){     \
    Node* node = (Node*)malloc(sizeof(Node));           \
    node->data=data;                                    \
    node->next=NULL;                                    \
    node->add = (struct linkedList*)add_##type;         \
    node->printNode = print_##type;                     \
    return node;                                        \
}

new(int)

new(string)

#define genericNew(data) _Generic((data),   \
int*:newNode_int,                           \
string*:newNode_string                      \
)(data)


#endif //GENERICLINKEDLIST_LIBRARY_H
