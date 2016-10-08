#include<iostream>
#include<vector>

using namespace std;

int findPeakElement(vector<int>& nums) {
    int index = -1;
    if (nums.empty()) return index;
    if (nums.size() == 1) return 0;

    int left = 0;
    int right = nums.size() - 1;
    int mid;

    if (nums[0] > nums[1]) return 0;
    if (nums[nums.size()-2] < nums[nums.size()-1]) return nums.size() - 1;

    while (left <= right) {
        mid = (left + right) / 2;
        if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1]) {
            left = mid + 1;
        } else if (nums[mid - 1] > nums[mid] && nums[mid] > nums[mid + 1]) {
            right = mid - 1;
        } else if (nums[mid -1] > nums[mid] && nums[mid] < nums[mid + 1]) {
            right = mid - 1;
        } else {
            return mid;
        }
    }

    return -1; //should never happen;
}

int main(int argc, char *argv[])
{
    std::vector<int> numbers {2, 4, 6, 8};
    vector<int> a {1, 2, 3, 1};
    cout<<findPeakElement(a)<<endl;
    return 0;
}
