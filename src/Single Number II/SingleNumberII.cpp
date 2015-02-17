#include <iostream>

using namespace std;

int singleNumber(int A[], int n) {
    int result = 0;
    int count[32] = {0};
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < n; j++) {
            if ((A[j] >> i) & 1) {
                count[i]++;
            }
        }
        result |= (count[i] % 3) << i;
    }
    return result;
}



int main(int argc, char *argv[])
{
    int a[] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 4};
    cout<<singleNumber(a, 10)<<endl;
    return 0;
}
