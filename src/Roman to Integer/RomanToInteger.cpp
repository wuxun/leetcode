#include <iostream>

using namespace std;

int romanToInt(string s) {
    string roman_str = "IVXLCDM";
    int roman_nums[] = {1, 5, 10, 50, 100, 500, 1000};

    int result = 0;

    if (s.empty()) return result;

    int index = 0;
    for (int i = 0; i < s.size(); i++) {
        index = roman_str.find(s[i]);
        if (index < roman_str.size() - 1
            && i < s.size() -1) {
            int nextIndex = roman_str.find(s[i+1]);
            if (index < nextIndex) {
                result += roman_nums[nextIndex] - roman_nums[index];
                i++;
            } else {
                result += roman_nums[index];
            }
        } else {
            result += roman_nums[index];
        }
    }

    return result;
}

void test(string s) {
    cout<<s<<" "<<romanToInt(s)<<endl;
}

int main(int argc, char *argv[])
{
    test("I");
    test("II");
    test("III");
    test("IV");
    test("V");
    test("XCVII");
    test("DCCCXC");
    test("MDCCC");
    return 0;
}
