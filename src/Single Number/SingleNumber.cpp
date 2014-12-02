// Source:https://oj.leetcode.com/problems/single-number/
// Author:wuxun
// Date  :2014-12-02

/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Hide Tags
*/

#include <iostream>
#include <map>

using namespace std;

int singleNumber(int A[], int n) {
    map<int, int> map;
    for(int i=0; i<n; i++){
        auto search = map.find(A[i]);
        if(search != map.end()){
            map.erase(search);
        }else{
            map[A[i]] = 1;
        }
    }
    auto it = map.cbegin();
    return it->first;
}

//Author:Hao Chen
int singleNumber2(int A[], int n) {
    int s = 0;
    for (int i=0; i<n; i++) {
        s ^= A[i];
    }
    return s;
}

int main (int argc, char const *argv[])
{
    int a[] = {1,1,2,2,3,4,4};
    cout<<singleNumber2(a, 7)<<endl;
    return 0;
}
