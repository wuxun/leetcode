#include <iostream>
#include <limits.h>

using namespace std;

int max(int a, int b) {
    return a > b ? a : b;
}

int max(int a, int b, int c) {
    return max(max(a, b), c);
}

int maxSubArray1(int A[], int n) {
    int *sum = new int[n];
    sum[0] = A[0];
    int max_sum = A[0];
    for (int i=1; i<n ;i++) {
        sum[i] = max(A[i], A[i] + sum[i - 1]);
        max_sum = max(sum[i], max_sum);
    }

    delete[] sum;
    return max_sum;
}

int maxSubArray2(int A[], int n) {
    int sum = 0;
    int max_sum = INT_MIN;
    for (int i=0; i<n; i++) {
        sum += A[i];
        max_sum = max(sum, max_sum);
        if (sum < 0) {
            sum = 0;
        }
    }
    return max_sum;
}

int maxCrossArray(int A[], int mid, int start, int end) {
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = mid - 1; i >= start; i--) {
        sum += A[i];
        if (sum > left_sum) {
            left_sum = sum;
        }
    }

    sum = 0;
    int right_sum = INT_MIN;
    for (int i = mid; i < end; i++) {
        sum += A[i];
        if (sum > right_sum) {
            right_sum = sum;
        }
    }

    return left_sum + right_sum;
}

int divideSubArraySum(int A[], int start, int end) {
    if (start + 1 == end) return A[start];

    int mid = (start + end) / 2;
    return max(divideSubArraySum(A, start, mid),
               divideSubArraySum(A, mid, end),
               maxCrossArray(A, mid, start, end));
}

int maxSubArray3(int A[], int n) {
    if (n == 1) return A[0];

    return divideSubArraySum(A, 0, n);
}

int main(int argc, char *argv[])
{
    int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout<<maxSubArray1(a, 9)<<endl;
    cout<<maxSubArray2(a, 9)<<endl;
    cout<<maxSubArray3(a, 9)<<endl;
    return 0;
}

