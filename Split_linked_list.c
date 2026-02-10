#include <stdlib.h>

struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    *returnSize = k;
    struct ListNode** res = (struct ListNode**)malloc(sizeof(struct ListNode*) * k);

    int len = 0;
    struct ListNode* cur = head;
    while (cur) {
        len++;
        cur = cur->next;
    }

    int base = len / k;
    int extra = len % k;

    cur = head;
    for (int i = 0; i < k; i++) {
        res[i] = cur;
        int partSize = base + (i < extra ? 1 : 0);
        for (int j = 1; j < partSize && cur; j++) {
            cur = cur->next;
        }
        if (cur) {
            struct ListNode* next = cur->next;
            cur->next = NULL;
            cur = next;
        }
    }
    return res;
}
