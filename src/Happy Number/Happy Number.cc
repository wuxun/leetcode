class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n >= 10) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        sum += n * n;
        return sum;
    }

    bool isHappy(int n) {
        if (n == 1) {
            return true;
        } else if (n == 4) {
            return false;
        } else {
            return isHappy(digitSum(n));
        }
    }
};
