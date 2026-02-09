int totalSteps(int* nums, int numsSize) {
    int stackVal[numsSize];
    int stackSteps[numsSize];
    int top = -1;
    int answer = 0;
    for (int i = 0; i < numsSize; i++) {
        int steps = 0;
        while (top != -1 && stackVal[top] <= nums[i]) {
            if (stackSteps[top] > steps)
                steps = stackSteps[top];
            top--;
        }
        if (top != -1)
            steps = steps + 1;
        else
            steps = 0;
        top++;
        stackVal[top] = nums[i];
        stackSteps[top] = steps;
        if (steps > answer)
            answer = steps;
    }
    return answer;
}
