#include <stdlib.h>
#include <limits.h>

int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
    int* ans = malloc(2 * sizeof(int));
    *returnSize = 2;
    ans[0] = -1;
    ans[1] = -1;

    if (!head || !head->next || !head->next->next) return ans;

    int idx = 1;
    int first = -1, last = -1, prev = head->val;
    struct ListNode* cur = head->next;
    int mind = INT_MAX;

    while (cur->next) {
        int next = cur->next->val;

        if ((cur->val > prev && cur->val > next) ||
            (cur->val < prev && cur->val < next)) {

            if (first == -1) first = idx;
            else mind = idx - last < mind ? idx - last : mind;

            last = idx;
        }

        prev = cur->val;
        cur = cur->next;
        idx++;
    }

    if (first != -1 && last != first) {
        ans[0] = mind;
        ans[1] = last - first;
    }

    return ans;
}
