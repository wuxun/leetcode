#include<iostream>
#include<algorithm>

using namespace std;

string reverseCharacter(string &s, int begin, int end) {
    int i=begin;
    int j=end;
    while (i < j) {
        swap(s[i++], s[j--]);
    }
    return s.substr(begin, end - begin + 1);
}

void reverseWords(string &s) {
    int word_begin = 0;
    bool word_begin_set = false;
    string ret("");
    for (int i=0; i<s.length(); i++) {
        if (s[i] == ' ') {
            if (word_begin_set) {
                if (!ret.empty()) ret += " ";
                ret += reverseCharacter(s, word_begin, i-1);
                word_begin_set = false;
            }
        } else {
            if (!word_begin_set) {
                word_begin = i;
                word_begin_set = true;
            }
            if (i == s.length() -1) {
                if (!ret.empty()) ret += " ";
                ret += reverseCharacter(s, word_begin, i);
            }
        }
    }

    reverseCharacter(ret, 0, ret.length()-1);
    s = ret;
}

int main(int argc, char *argv[])
{
    string s(" a b     asldfkja");
    reverseWords(s);
    cout<<s;
    return 0;
}
