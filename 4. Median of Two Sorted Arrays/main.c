#include <stdio.h>
#include <stdlib.h>


int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}


int findKth(int* nums1, int size1, int* nums2, int size2, int k) {
    if (size1 > size2) {
        return findKth(nums2, size2, nums1, size1, k);
    }

    if (size1 == 0) {
        return nums2[k - 1];
    }

    if (k == 1) {
        return min(nums1[0], nums2[0]);
    }

    int idx1 = min(k / 2, size1);
    int idx2 = k - idx1;
    int val1 = nums1[idx1 - 1];
    int val2 = nums2[idx2 - 1];

    if (val1 == val2) {
        return val1;
    } else if (val1 < val2) {
        return findKth(nums1 + idx1, size1 - idx1, nums2, size2, k - idx1);
    } else {
        return findKth(nums1, size1, nums2 + idx2, size2 - idx2, k - idx2);
    }
}


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int totalSize = nums1Size + nums2Size;

    if (totalSize % 2 == 1) {
        return findKth(nums1, nums1Size, nums2, nums2Size, (totalSize / 2) + 1);
    } else {
        int left = findKth(nums1, nums1Size, nums2, nums2Size, totalSize / 2);
        int right = findKth(nums1, nums1Size, nums2, nums2Size, (totalSize / 2) + 1);
        return (left + right) / 2.0;
    }
}