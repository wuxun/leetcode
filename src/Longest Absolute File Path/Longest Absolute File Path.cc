#include <iostream>
#include <stack>

using namespace std;

int lengthLongestPath(string input) {
    stack<int> lenStack;
    int max = 0;
    int currentLevel = 0;
    int lastLevel = -1;
    int currentLen = 0;
    bool newLevel = true;
    bool isFile = false;

    for (int i=0; i<=input.length(); i++) {
        if (input[i] == '\n' || i == input.length()) {
            // new level
            cout<<"len:"<<currentLen
                <<" isFile:"<<isFile;

            int parentLen = 0;
            while (lastLevel >= currentLevel && !lenStack.empty()) {
                lenStack.pop();
                lastLevel--;
            }
            if (!lenStack.empty()) {
                parentLen = lenStack.top();
            }
            cout<<" LastLen:"<<(lenStack.empty() ? 0 : lenStack.top())<<endl;
            int currentSize = parentLen + 1 + currentLen;
            if (currentSize > max && isFile) {
                max = currentSize;
                cout<<max<<endl;
            }
            lenStack.push(currentSize);
            lastLevel++;
            newLevel = true;
            currentLen = 0;
            currentLevel = 0;
            isFile = false;
        } else {
            if (newLevel && input[i] == '\t') {
                currentLevel++;
            } else {
                if (input[i] == '.') {
                    isFile = true;
                }
                newLevel = false;
                currentLen++;
            }
        }
    }
    return max == 0 ? 0 : max - 1;
}

int main(int argc, char *argv[])
{
    cout<<lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext")<<endl;
    return 0;
}
