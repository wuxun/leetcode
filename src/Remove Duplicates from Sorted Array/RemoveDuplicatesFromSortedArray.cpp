// Source: https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/
// Author: wuxun
// Date  : 2014-10-26

/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
*/


class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n < 0 ) return 0;
        if (n <= 1) return n;
        int index = 0;
        for(int i=1; i<n; i++){
            if(A[i] == A[index]){
                continue;
            }
            A[++index] = A[i];
        }

        return index + 1;
    }
};