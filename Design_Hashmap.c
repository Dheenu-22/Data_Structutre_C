#include <stdlib.h>
typedef struct {
    int *arr;
} MyHashMap;
MyHashMap* myHashMapCreate() {
    MyHashMap* obj = (MyHashMap*)malloc(sizeof(MyHashMap));
    obj->arr = (int*)malloc(sizeof(int) * 1000001);
    for (int i = 0; i <= 1000000; i++) {
        obj->arr[i] = -1;
    }
    return obj;
}
void myHashMapPut(MyHashMap* obj, int key, int value) {
    obj->arr[key] = value;
}
int myHashMapGet(MyHashMap* obj, int key) {
    return obj->arr[key];
}
void myHashMapRemove(MyHashMap* obj, int key) {
    obj->arr[key] = -1;
}
void myHashMapFree(MyHashMap* obj) {
    free(obj->arr);
    free(obj);
}
