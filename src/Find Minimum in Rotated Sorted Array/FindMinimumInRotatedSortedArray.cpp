#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int findMin(vector<int> &num) {
    int front = 0;
    int end = num.size() - 1;
    int mid;

    if (num[front] <= num[end]) return num[front];

    while (front <= end) {
        mid = (front + end) / 2;
        if (num[front] > num[mid]) {
            end = mid;
        } else if (num[front] < num[mid]) {
            front = mid;
        } else {
            return num[mid + 1];
        }
    }
}

int main(int argc, char *argv[])
{
    int a[] = {0, 1, 2};
    vector<int> num(a, a + sizeof(a)/sizeof(a[0]));
    cout<<findMin(num)<<endl;
    return 0;
}
