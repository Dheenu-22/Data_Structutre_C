#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int key;
    int value;
    int freq;
    struct Node *prev;
    struct Node *next;
} Node;
typedef struct {
    Node *head;
    Node *tail;
} DList;
typedef struct {
    int capacity;
    int size;
    int minFreq;
    Node **keyTable;   
    DList **freqTable;  
} LFUCache;
DList* createList() {
    DList* list = (DList*)malloc(sizeof(DList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}
void addFront(DList* list, Node* node) {
    node->prev = NULL;
    node->next = list->head;

    if (list->head)
        list->head->prev = node;
    else
        list->tail = node;

    list->head = node;
}
void removeNode(DList* list, Node* node) {
    if (node->prev)
        node->prev->next = node->next;
    else
        list->head = node->next;
    if (node->next)
        node->next->prev = node->prev;
    else
        list->tail = node->prev;
}
LFUCache* lFUCacheCreate(int capacity) {
    LFUCache* cache = (LFUCache*)malloc(sizeof(LFUCache));
    cache->capacity = capacity;
    cache->size = 0;
    cache->minFreq = 0;
    cache->keyTable = (Node**)calloc(100001, sizeof(Node*));
    cache->freqTable = (DList**)calloc(100001, sizeof(DList*));
    return cache;
}
int lFUCacheGet(LFUCache* obj, int key) {
    Node* node = obj->keyTable[key];
    if (!node) return -1;
    int freq = node->freq;
    removeNode(obj->freqTable[freq], node);
    if (!obj->freqTable[freq]->head && obj->minFreq == freq)
        obj->minFreq++;
    node->freq++;
    if (!obj->freqTable[node->freq])
        obj->freqTable[node->freq] = createList();
    addFront(obj->freqTable[node->freq], node);
    return node->value;
}
void lFUCachePut(LFUCache* obj, int key, int value) {
    if (obj->capacity == 0) return;
    if (obj->keyTable[key]) {
        obj->keyTable[key]->value = value;
        lFUCacheGet(obj, key);
        return;
    }
    if (obj->size == obj->capacity) {
        DList* list = obj->freqTable[obj->minFreq];
        Node* evict = list->tail;

        removeNode(list, evict);
        obj->keyTable[evict->key] = NULL;
        free(evict);
        obj->size--;
    }
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->freq = 1;
    node->prev = node->next = NULL;

    if (!obj->freqTable[1])
        obj->freqTable[1] = createList();

    addFront(obj->freqTable[1], node);
    obj->keyTable[key] = node;
    obj->minFreq = 1;
    obj->size++;
}
void lFUCacheFree(LFUCache* obj) {
    for (int i = 0; i <= 100000; i++) {
        if (obj->keyTable[i])
            free(obj->keyTable[i]);
        if (obj->freqTable[i])
            free(obj->freqTable[i]);
    }
    free(obj->keyTable);
    free(obj->freqTable);
    free(obj);
}
