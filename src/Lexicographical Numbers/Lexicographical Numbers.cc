#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void genLexicalOrder(vector<int> &ret, int pre, int depth, int max, bool firstCall) {
    if (depth > 0) {
        for (int i=0; i<10; i++) {
            if (firstCall && i == 0) {
                firstCall = false;
                continue;
            }
            int current = pre * 10 + i;
            if (current <= max) {
                ret.push_back(current);
            }

            genLexicalOrder(ret, current, depth - 1, max, false);
        }
    }
}

vector<int> lexicalOrder(int n) {
    vector<int> ret;

    int pre = 0;
    bool firstCall = true;
    int max = n;

    int depth = 0;
    while (n/10 > 0) {
        depth++;
        n /= 10;
    }
    depth++;

    genLexicalOrder(ret, pre, depth, max, firstCall);
    return ret;
}

int main(int argc, char *argv[])
{
    vector<int> ret = lexicalOrder(100);
    for (int i=0; i<ret.size(); i++) {
        cout<<ret[i]<<" ";
    }
    cout<<endl;

    return 0;
}
