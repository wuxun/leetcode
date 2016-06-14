#include <iostream>
#include <algorithm>

using namespace std;

int min(int x, int y, int z) {
    return std::min(x, std::min(y,z));
}

int minDistance(string word1, string word2) {

    int size1 = word1.size();
    int size2 = word2.size();

    if (size1 == 0) return size2;
    if (size2 == 0) return size1;

    int m[size1+1][size2+1];

    for (int i=0; i<=size1; i++) {
        m[i][0] = i;
    }

    for (int i=0; i<=size2; i++) {
        m[0][i] = i;
    }

    int row, col;
    for (row=1; row<=size1; row++) {
        for (col = 1; col<=size2; col++) {
            if (word1[row-1] == word2[col-1]) {
                m[row][col] = m[row-1][col-1];
            } else {
                m[row][col] = min(m[row-1][col],
                                  m[row-1][col-1],
                                  m[row][col-1]) + 1;
            }
        }

    }

    return m[size1][size2];
}

int main(int argc, char *argv[])
{
    cout << minDistance("abb", "abccb");
    return 0;
}
