#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEVEL 16

typedef struct Node {
    int val;
    struct Node* next[MAX_LEVEL];
} Node;

typedef struct {
    Node* head;
    int level;
} Skiplist;

int randomLevel() {
    int lvl = 1;
    while ((rand() & 1) && lvl < MAX_LEVEL) lvl++;
    return lvl;
}

Node* createNode(int val, int level) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->val = val;
    for (int i = 0; i < MAX_LEVEL; i++) n->next[i] = NULL;
    return n;
}

Skiplist* skiplistCreate() {
    Skiplist* s = (Skiplist*)malloc(sizeof(Skiplist));
    s->level = 1;
    s->head = createNode(-1, MAX_LEVEL);
    return s;
}

bool skiplistSearch(Skiplist* obj, int target) {
    Node* cur = obj->head;
    for (int i = obj->level - 1; i >= 0; i--) {
        while (cur->next[i] && cur->next[i]->val < target)
            cur = cur->next[i];
    }
    cur = cur->next[0];
    return cur && cur->val == target;
}

void skiplistAdd(Skiplist* obj, int num) {
    Node* update[MAX_LEVEL];
    Node* cur = obj->head;

    for (int i = obj->level - 1; i >= 0; i--) {
        while (cur->next[i] && cur->next[i]->val < num)
            cur = cur->next[i];
        update[i] = cur;
    }

    int lvl = randomLevel();
    if (lvl > obj->level) {
        for (int i = obj->level; i < lvl; i++)
            update[i] = obj->head;
        obj->level = lvl;
    }

    Node* n = createNode(num, lvl);
    for (int i = 0; i < lvl; i++) {
        n->next[i] = update[i]->next[i];
        update[i]->next[i] = n;
    }
}

bool skiplistErase(Skiplist* obj, int num) {
    Node* update[MAX_LEVEL];
    Node* cur = obj->head;

    for (int i = obj->level - 1; i >= 0; i--) {
        while (cur->next[i] && cur->next[i]->val < num)
            cur = cur->next[i];
        update[i] = cur;
    }

    cur = cur->next[0];
    if (!cur || cur->val != num) return false;

    for (int i = 0; i < obj->level; i++) {
        if (update[i]->next[i] != cur) break;
        update[i]->next[i] = cur->next[i];
    }

    free(cur);
    while (obj->level > 1 && obj->head->next[obj->level - 1] == NULL)
        obj->level--;

    return true;
}

void skiplistFree(Skiplist* obj) {
    Node* cur = obj->head->next[0];
    while (cur) {
        Node* temp = cur->next[0];
        free(cur);
        cur = temp;
    }
    free(obj->head);
    free(obj);
}
