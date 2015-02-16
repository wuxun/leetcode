#include <iostream>
#include <vector>
#include <map>

using namespace std;

int majorityElement1(vector<int> &num) {
    map<int, int> appearTimes;

    if (num.size() == 1) return num[0];

    for (int tmpNum : num) {
        auto search = appearTimes.find(tmpNum);
        if (search != appearTimes.end()) {
            appearTimes[tmpNum]++;
            if (appearTimes[tmpNum] > num.size()/2) return tmpNum;
        } else {
            appearTimes[tmpNum] = 1;
        }
    }
    return -1;
}

int majorityElement2(vector<int> &num) {
    int majority;
    int count = 0;

    for (int tmpNum : num) {
        if (count == 0) {
            majority = tmpNum;
            count++;
        } else {
            majority == tmpNum ? count++ : count--;
        }
    }

    return majority;
}

int main(int argc, char *argv[])
{
    vector<int> a;
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    cout<<majorityElement1(a)<<endl;
    cout<<majorityElement2(a)<<endl;
    return 0;
}
