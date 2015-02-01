#include <iostream>

using namespace std;

int searchInsert(int A[], int n, int target) {
    int left = 0;
    int right = n - 1;
    int mid = 0;

    if (n == 0) return 0;

    while (left <= right) {
        mid = (left + right) / 2;
        if (A[mid] == target) {
            return mid;
        } else if (A[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return A[mid] < target ? mid + 1 : mid;
}

int main(int argc, char *argv[])
{
    const int N = 11;
    int A[N];
    for (int i = 0, j=0; i < N; i++, j+=2) {
        A[i] = j;
        cout<<A[i]<<" ";
    }
    cout<<endl;

    for (int i=0; i<N; i++) {
        cout<<searchInsert(A, N, i)<<endl<<endl;
    }

    return 0;
}
