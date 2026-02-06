#include <stdlib.h>
int** spiralMatrix(int m, int n, struct ListNode* head,
                   int* returnSize, int** returnColumnSizes) {
    int** mat = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        mat[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            mat[i][j] = -1; 
        }
    }
    *returnSize = m;
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = n;
    }
    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;
    struct ListNode* curr = head;
    while (curr != NULL && top <= bottom && left <= right) {
        for (int j = left; j <= right && curr != NULL; j++) {
            mat[top][j] = curr->val;
            curr = curr->next;
        }
        top++;
        for (int i = top; i <= bottom && curr != NULL; i++) {
            mat[i][right] = curr->val;
            curr = curr->next;
        }
        right--;
        for (int j = right; j >= left && curr != NULL; j--) {
            mat[bottom][j] = curr->val;
            curr = curr->next;
        }
        bottom--;
        for (int i = bottom; i >= top && curr != NULL; i--) {
            mat[i][left] = curr->val;
            curr = curr->next;
        }
        left++;
    }
    return mat;
}
