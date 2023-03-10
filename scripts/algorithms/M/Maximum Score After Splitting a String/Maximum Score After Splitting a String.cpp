class Solution {
public:
    int maxScore(string s) {
        int ones = 0;
        int res = -s.length();
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == '1') ones += 2;
            if (i - ones > res) res = i - ones;
        };

        ones >>= 1;
        if (s[s.length() - 1] == '1') ones++;

        return ones + res + 1;
    }
};