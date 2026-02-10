#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
} MyCircularDeque;

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* dq = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    dq->capacity = k;
    dq->size = 0;
    dq->front = 0;
    dq->rear = -1;
    dq->arr = (int*)malloc(sizeof(int) * k);
    return dq;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (obj->size == obj->capacity)
        return false;
    obj->front = (obj->front - 1 + obj->capacity) % obj->capacity;
    obj->arr[obj->front] = value;
    if (obj->size == 0)
        obj->rear = obj->front;
    obj->size++;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (obj->size == obj->capacity)
        return false;
    obj->rear = (obj->rear + 1) % obj->capacity;
    obj->arr[obj->rear] = value;
    if (obj->size == 0)
        obj->front = obj->rear;
    obj->size++;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (obj->size == 0)
        return false;
    obj->front = (obj->front + 1) % obj->capacity;
    obj->size--;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (obj->size == 0)
        return false;
    obj->rear = (obj->rear - 1 + obj->capacity) % obj->capacity;
    obj->size--;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (obj->size == 0)
        return -1;
    return obj->arr[obj->front];
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (obj->size == 0)
        return -1;
    return obj->arr[obj->rear];
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->size == 0;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->size == obj->capacity;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->arr);
    free(obj);
}
