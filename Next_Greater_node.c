#include <stdlib.h>

int* nextLargerNodes(struct ListNode* head, int* returnSize) {
    int vals[10000];
    int n = 0;
    struct ListNode* cur = head;

    while (cur) {
        vals[n++] = cur->val;
        cur = cur->next;
    }

    int* res = (int*)calloc(n, sizeof(int));
    int stack[10000];
    int top = -1;

    for (int i = 0; i < n; i++) {
        while (top >= 0 && vals[stack[top]] < vals[i]) {
            res[stack[top--]] = vals[i];
        }
        stack[++top] = i;
    }

    *returnSize = n;
    return res;
}
