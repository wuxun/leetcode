#include <iostream>

using namespace std;

int numTrees1(int n) {
    if (n <= 0 ) return 0;
    if (n == 1 ) return 1;

    int* array = new int[n];
    array[0] = 1;
    array[1] = 1;

    for (int i = 2; i <= n; i++) {
        array[i] = 0;
        for (int j = 1; j <= i; j++) {
            array[i] += array[j - 1] * array[i - j];
        }
    }

    int temp = array[n];
    delete[] array;
    return temp;
}

int numTrees(int n) {
    if (n <= 0 ) return 0;
    if (n == 1 ) return 1;
    int num = 0;
    for (int i = 1; i <= n; i++) {
        if (i== 1 || i == n) {
            num += numTrees(n - 1);
        } else {
            num += numTrees(i - 1) * numTrees(n-i);
        }
    }
    return num;
}

int main(int argc, char** argv) {
    for (int i=0; i<10; i++){
        cout<<numTrees(i)<<" "<<numTrees1(i)<<endl;
    }
}
