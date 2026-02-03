#include <stdlib.h>
#include <time.h>
typedef struct {
    struct ListNode* head;
} Solution;
Solution* solutionCreate(struct ListNode* head) {
    Solution* obj = (Solution*)malloc(sizeof(Solution));
    obj->head = head;
    srand(time(NULL));
    return obj;
}
int solutionGetRandom(Solution* obj) {
    struct ListNode* curr = obj->head;
    int res = curr->val;
    int i = 1;
    while (curr) {
        if (rand() % i == 0)
            res = curr->val;
        curr = curr->next;
        i++;
    }
    return res;
}
void solutionFree(Solution* obj) {
    free(obj);
}
