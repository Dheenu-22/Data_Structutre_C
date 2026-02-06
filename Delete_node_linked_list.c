#include <stdlib.h>
struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
    int present[100001] = {0};
    for (int i = 0; i < numsSize; i++) {
        present[nums[i]] = 1;
    }
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;
    struct ListNode* curr = head;
    while (curr != NULL) {
        if (present[curr->val]) {
            prev->next = curr->next;
        } else {
            prev = curr;
        }
        curr = curr->next;
    }
    return dummy.next;
}
