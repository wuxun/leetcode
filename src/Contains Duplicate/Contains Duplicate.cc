#include <set>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::set<int> allNums;
        for (int i = 0; i < nums.size(); i++) {
            auto result = allNums.insert(nums[i]);

            if (!result.second) return true;
        }
        return false;
    }
};
