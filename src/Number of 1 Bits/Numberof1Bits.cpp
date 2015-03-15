#include <iostream>

using namespace std;

int hammingWeight1(uint32_t n) {
    int cnt = 0;
    while (n != 0) {
        n &= (n - 1);
        cnt++;
    }

    return cnt;
}

int hammingWeight2(uint32_t n) {
    n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
    n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
    n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
    return n;
}

int main(int argc, char *argv[])
{
    cout<<hammingWeight2(0)<<endl;
    cout<<hammingWeight2(1)<<endl;
    cout<<hammingWeight2(7)<<endl;
    return 0;
}

