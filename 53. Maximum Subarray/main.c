#include <stdio.h>
#include <limits.h>



int maxSubArrayRecursive(int* nums, int left, int right) {
    if (left == right) {
        return nums[left];
    }

    int mid = (left + right) / 2;

   
    int left_max = maxSubArrayRecursive(nums, left, mid);
    int right_max = maxSubArrayRecursive(nums, mid + 1, right);
    int cross_max = mergeAndFindMax(nums, left, mid, right);

   
    if (left_max >= right_max && left_max >= cross_max)
        return left_max;
    else if (right_max >= left_max && right_max >= cross_max)
        return right_max;
    else
        return cross_max;
}


int mergeAndFindMax(int* nums, int left, int mid, int right) {
    int left_sum = INT_MIN, right_sum = INT_MIN;
    int sum = 0;

    // Soma máxima no lado esquerdo
    for (int i = mid; i >= left; i--) {
        sum += nums[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    // Soma máxima no lado direito
    for (int i = mid + 1; i <= right; i++) {
        sum += nums[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return left_sum + right_sum;
}