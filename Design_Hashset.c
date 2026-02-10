#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    bool *arr;
} MyHashSet;

MyHashSet* myHashSetCreate() {
    MyHashSet* obj = (MyHashSet*)malloc(sizeof(MyHashSet));
    obj->arr = (bool*)calloc(1000001, sizeof(bool));
    return obj;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    obj->arr[key] = true;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    obj->arr[key] = false;
}

bool myHashSetContains(MyHashSet* obj, int key) {
    return obj->arr[key];
}

void myHashSetFree(MyHashSet* obj) {
    free(obj->arr);
    free(obj);
}
