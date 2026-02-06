#include <stdlib.h>
#include <string.h>
typedef struct {
    char* left;
    char* right;
    int lsz, rsz;
    int cap;
} TextEditor;
TextEditor* textEditorCreate() {
    TextEditor* obj = (TextEditor*)malloc(sizeof(TextEditor));
    obj->cap = 1000000; 
    obj->left = (char*)malloc(obj->cap);
    obj->right = (char*)malloc(obj->cap);
    obj->lsz = 0;
    obj->rsz = 0;
    return obj;
}
void textEditorAddText(TextEditor* obj, char* text) {
    for (int i = 0; text[i]; i++) {
        obj->left[obj->lsz++] = text[i];
    }
}
int textEditorDeleteText(TextEditor* obj, int k) {
    int del = k < obj->lsz ? k : obj->lsz;
    obj->lsz -= del;
    return del;
}
char* getLast10(TextEditor* obj) {
    int len = obj->lsz < 10 ? obj->lsz : 10;
    char* res = (char*)malloc(len + 1);
    for (int i = 0; i < len; i++) {
        res[i] = obj->left[obj->lsz - len + i];
    }
    res[len] = '\0';
    return res;
}
char* textEditorCursorLeft(TextEditor* obj, int k) {
    while (k-- > 0 && obj->lsz > 0) {
        obj->right[obj->rsz++] = obj->left[--obj->lsz];
    }
    return getLast10(obj);
}
char* textEditorCursorRight(TextEditor* obj, int k) {
    while (k-- > 0 && obj->rsz > 0) {
        obj->left[obj->lsz++] = obj->right[--obj->rsz];
    }
    return getLast10(obj);
}
void textEditorFree(TextEditor* obj) {
    free(obj->left);
    free(obj->right);
    free(obj);
}
