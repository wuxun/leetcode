class Solution {
public:
    int addDigits(int num) {
        if (num < 10) {
            return num;
        } else {
            return addDigits(num % 10 + addDigits(num / 10));
        }
    }

    int addDigits2(int num) {
        if (num % 9 == 0 && num != 0) {
            return 9;
        } else {
            return num % 9;
        }
    }
};
