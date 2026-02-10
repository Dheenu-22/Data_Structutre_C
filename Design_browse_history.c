#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* url;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* curr;
} BrowserHistory;

Node* newNode(char* url) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->url = strdup(url);
    n->prev = NULL;
    n->next = NULL;
    return n;
}

BrowserHistory* browserHistoryCreate(char* homepage) {
    BrowserHistory* obj = (BrowserHistory*)malloc(sizeof(BrowserHistory));
    obj->curr = newNode(homepage);
    return obj;
}

void browserHistoryVisit(BrowserHistory* obj, char* url) {
    Node* temp = obj->curr->next;
    while (temp) {
        Node* del = temp;
        temp = temp->next;
        free(del->url);
        free(del);
    }
    obj->curr->next = newNode(url);
    obj->curr->next->prev = obj->curr;
    obj->curr = obj->curr->next;
}

char* browserHistoryBack(BrowserHistory* obj, int steps) {
    while (steps-- && obj->curr->prev)
        obj->curr = obj->curr->prev;
    return obj->curr->url;
}

char* browserHistoryForward(BrowserHistory* obj, int steps) {
    while (steps-- && obj->curr->next)
        obj->curr = obj->curr->next;
    return obj->curr->url;
}

void browserHistoryFree(BrowserHistory* obj) {
    Node* temp = obj->curr;
    while (temp->prev)
        temp = temp->prev;
    while (temp) {
        Node* del = temp;
        temp = temp->next;
        free(del->url);
        free(del);
    }
    free(obj);
}
