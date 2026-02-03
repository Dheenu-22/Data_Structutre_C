#include <stdbool.h>
#include <stdlib.h>
int numComponents(struct ListNode* head, int* nums, int numsSize) {
    bool *hash = (bool*)calloc(10000, sizeof(bool)); 
    for (int i = 0; i < numsSize; i++)
        hash[nums[i]] = true;
    int count = 0;
    struct ListNode* curr = head;
    while (curr != NULL) {
        if (hash[curr->val] && (curr->next == NULL || !hash[curr->next->val]))
            count++;
        curr = curr->next;
    }
    free(hash);
    return count;
}
