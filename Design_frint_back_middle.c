#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} FrontMiddleBackQueue;

FrontMiddleBackQueue* frontMiddleBackQueueCreate() {
    FrontMiddleBackQueue* q = (FrontMiddleBackQueue*)malloc(sizeof(FrontMiddleBackQueue));
    q->head = q->tail = NULL;
    q->size = 0;
    return q;
}

void frontMiddleBackQueuePushFront(FrontMiddleBackQueue* obj, int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->val = val;
    n->prev = NULL;
    n->next = obj->head;
    if (obj->head) obj->head->prev = n;
    else obj->tail = n;
    obj->head = n;
    obj->size++;
}

void frontMiddleBackQueuePushBack(FrontMiddleBackQueue* obj, int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->val = val;
    n->next = NULL;
    n->prev = obj->tail;
    if (obj->tail) obj->tail->next = n;
    else obj->head = n;
    obj->tail = n;
    obj->size++;
}

void frontMiddleBackQueuePushMiddle(FrontMiddleBackQueue* obj, int val) {
    if (obj->size == 0) {
        frontMiddleBackQueuePushFront(obj, val);
        return;
    }
    int mid = obj->size / 2;
    Node* cur = obj->head;
    for (int i = 0; i < mid; i++) cur = cur->next;

    Node* n = (Node*)malloc(sizeof(Node));
    n->val = val;
    n->prev = cur->prev;
    n->next = cur;

    if (cur->prev) cur->prev->next = n;
    else obj->head = n;

    cur->prev = n;
    obj->size++;
}

int frontMiddleBackQueuePopFront(FrontMiddleBackQueue* obj) {
    if (obj->size == 0) return -1;
    Node* t = obj->head;
    int v = t->val;
    obj->head = t->next;
    if (obj->head) obj->head->prev = NULL;
    else obj->tail = NULL;
    free(t);
    obj->size--;
    return v;
}

int frontMiddleBackQueuePopBack(FrontMiddleBackQueue* obj) {
    if (obj->size == 0) return -1;
    Node* t = obj->tail;
    int v = t->val;
    obj->tail = t->prev;
    if (obj->tail) obj->tail->next = NULL;
    else obj->head = NULL;
    free(t);
    obj->size--;
    return v;
}

int frontMiddleBackQueuePopMiddle(FrontMiddleBackQueue* obj) {
    if (obj->size == 0) return -1;
    int mid = (obj->size - 1) / 2;
    Node* cur = obj->head;
    for (int i = 0; i < mid; i++) cur = cur->next;

    int v = cur->val;
    if (cur->prev) cur->prev->next = cur->next;
    else obj->head = cur->next;

    if (cur->next) cur->next->prev = cur->prev;
    else obj->tail = cur->prev;

    free(cur);
    obj->size--;
    return v;
}

void frontMiddleBackQueueFree(FrontMiddleBackQueue* obj) {
    Node* cur = obj->head;
    while (cur) {
        Node* t = cur;
        cur = cur->next;
        free(t);
    }
    free(obj);
}
