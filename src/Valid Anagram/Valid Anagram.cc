bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;

    int NUM = 26;
    int alphabet[NUM];
    memset(alphabet, 0, NUM * sizeof(alphabet[0]));

    for (int i = 0; i < s.size(); i++) {
        alphabet[s[i] - 'a'] += 1;
        alphabet[t[i] - 'a'] -= 1;
    }

    for (int j = 0; j < NUM; j++) {
        if (alphabet[j] != 0) {
            return false;
        }
    }
    return true;
}
