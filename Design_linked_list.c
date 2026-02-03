#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int val;
    struct Node* next;
} Node;
typedef struct {
    Node* head;
    int size;
} MyLinkedList;
MyLinkedList* myLinkedListCreate();
int myLinkedListGet(MyLinkedList* obj, int index);
void myLinkedListAddAtHead(MyLinkedList* obj, int val);
void myLinkedListAddAtTail(MyLinkedList* obj, int val);
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val);
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index);
void myLinkedListFree(MyLinkedList* obj);
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return -1;
    Node* curr = obj->head;
    for (int i = 0; i < index; i++)
        curr = curr->next;
    return curr->val;
}
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = obj->head;
    obj->head = newNode;
    obj->size++;
}
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    if (!obj->head) {
        obj->head = newNode;
    } else {
        Node* curr = obj->head;
        while (curr->next) curr = curr->next;
        curr->next = newNode;
    }
    obj->size++;
}
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size) return;
    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    Node* curr = obj->head;
    for (int i = 0; i < index - 1; i++)
        curr = curr->next;

    newNode->next = curr->next;
    curr->next = newNode;
    obj->size++;
}
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size) return;
    Node* temp;
    if (index == 0) {
        temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
    } else {
        Node* curr = obj->head;
        for (int i = 0; i < index - 1; i++)
            curr = curr->next;
        temp = curr->next;
        curr->next = temp->next;
        free(temp);
    }
    obj->size--;
}
void myLinkedListFree(MyLinkedList* obj) {
    Node* curr = obj->head;
    while (curr) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(obj);
}
