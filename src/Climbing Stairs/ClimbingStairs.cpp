#include <iostream>

using namespace std;

int climbStairs1(int n) {
    if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else {
        return climbStairs1(n - 1) + climbStairs1(n - 2);
    }
}

int climbStairs2(int n) {
    int *result = new int[n + 1];
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    }

    result[0] = 0;
    result[1] = 1;
    result[2] = 2;

    for (int i = 3; i <= n; i++) {
        result[i] = result[i-1] + result[i-2];
    }

    return result[n];
}

int main(int argc, char *argv[])
{
    cout<<climbStairs1(6)<<endl;
    return 0;
}
