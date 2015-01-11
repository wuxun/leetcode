#include <iostream>
#include <string>

using namespace std;

int titleToNumber(string s) {
    int number = 0;
    for (int i = 0; i < s.size(); i++) {
        number *= 26;
        number += (s[i] - 'A' + 1);
    }

    return number;
}

int main(int argc, char *argv[])
{
    cout<< "A:" << titleToNumber("A") << endl;
    cout<< "AA:" << titleToNumber("AA") << endl;
    cout<< "AAA:" << titleToNumber("AAA") << endl;
    cout<< "AB:" << titleToNumber("AB") << endl;
    return 0;
}
