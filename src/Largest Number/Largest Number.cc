#include<iostream>
#include<vector>

using namespace std;

bool static comp(string &s1, string &s2) {
    return s1+s2 > s2+s1;
}

string largestNumber(vector<int>& nums) {
    string ret;
    vector<string> vec;
    for (int num : nums) {
        vec.push_back(to_string(num));
    }

    sort(vec.begin(), vec.end(), comp);

    for (string str : vec) {
        ret += str;
    }

    if (ret[0] == '0') return "0";

    return ret;
}

int main(int argc, char *argv[])
{
    vector<int> a {1,2,3,4, 001, 100};
    cout<<largestNumber(a);
    return 0;
}

