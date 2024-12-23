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