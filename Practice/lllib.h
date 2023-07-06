#include <stdio.h>
#include <stdlib.h>

typedef int elementType;

typedef struct nodeType {
    elementType element;
    struct nodeType * next;
    struct nodeType * prev;
}node;

node* makeNewNode(elementType inputElement){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->element= inputElement;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

node* insertAtHead(elementType inputElement, node ** root){
    node* newNode = makeNewNode(inputElement);
    newNode->next= *root;
    return newNode;
}


node* insertAfterCur(elementType inputElement, node ** cur){
    node* newNode = makeNewNode(inputElement);
    node * nextNode = (*cur)->next->next;
    nextNode->prev= newNode;
    (*cur)->next = newNode;
    newNode->next = nextNode;
    newNode->prev = *cur;
    *cur = newNode;
    return newNode;
}

void deleteCurNode(node** root, node** cur){
    node* prevNode = (*cur)->prev;
    node* nextNode = (*cur)->next;
    free(*cur);
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
}

void readCurNode(node** cur){
    elementType readElement = (*cur)->element;
}

void* deleteFirstNode(node** root){
    node* nextNode = (*root)->next;
    nextNode->prev = NULL;
    free(*root);
    *root = nextNode;
}


void deleteLastNode(node** tail){
    node* prevNode = (*tail)->prev;
    prevNode->next=NULL;
    free(*tail);
    *tail = prevNode;
}

node* insertAtTail(elementType inputElement,node** tail){
    node* newNode = makeNewNode(inputElement);
    (*tail)->next = newNode;
    newNode->prev=*tail;
    *tail= newNode;
    return newNode;
}



