#include <stdlib.h>

struct ListNode* removeZeroSumSublists(struct ListNode* head) {
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;

    struct ListNode* mapNodes[2001] = {0};
    int mapSum[2001] = {0};
    int mapCount = 0;

    int prefix = 0;
    struct ListNode* cur = &dummy;

    while (cur) {
        prefix += cur->val;
        int found = -1;
        for (int i = 0; i < mapCount; i++) {
            if (mapSum[i] == prefix) {
                found = i;
                break;
            }
        }

        if (found != -1) {
            int temp = prefix;
            struct ListNode* node = mapNodes[found]->next;
            int p = found + 1;
            int sum = temp;
            while (node != cur) {
                sum += node->val;
                for (int j = found + 1; j < mapCount; j++) {
                    if (mapSum[j] == sum) {
                        for (int k = j; k < mapCount - 1; k++) {
                            mapSum[k] = mapSum[k + 1];
                            mapNodes[k] = mapNodes[k + 1];
                        }
                        mapCount--;
                        j--;
                    }
                }
                node = node->next;
            }
            mapNodes[found]->next = cur->next;
        } else {
            mapSum[mapCount] = prefix;
            mapNodes[mapCount] = cur;
            mapCount++;
        }

        cur = cur->next;
    }

    return dummy.next;
}
