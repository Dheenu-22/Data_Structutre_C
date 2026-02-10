#include <stdlib.h>
#include <stdbool.h>
typedef struct {
    int *arr;        
    int front;     
    int rear;       
    int size;       
    int capacity;   
} MyCircularQueue;
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    q->capacity = k;
    q->size = 0;
    q->front = 0;
    q->rear = -1;
    q->arr = (int*)malloc(sizeof(int) * k);
    return q;
}
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
        return false;
    obj->rear = (obj->rear + 1) % obj->capacity;
    obj->arr[obj->rear] = value;
    obj->size++;
    return true;
}
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return false;
    obj->front = (obj->front + 1) % obj->capacity;
    obj->size--;
    return true;
}
int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;

    return obj->arr[obj->front];
}
int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;

    return obj->arr[obj->rear];
}
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->size == 0;
}
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size == obj->capacity;
}
void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->arr);
    free(obj);
}
