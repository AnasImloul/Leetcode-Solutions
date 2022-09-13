// Runtime: 168 ms (Top 52.00%) | Memory: 173.7 MB (Top 19.81%)
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;

        string longest = "";

        for (int i = 0; i < s.size(); i++) {
            string sub1 = expand(s, i, i+1);
            string sub2 = expand(s, i, i);

            string sub3 = sub1.size() > sub2.size() ? sub1 : sub2;

            if(sub3.size() > longest.size()) {
                longest = sub3;
            }
        }
        return longest;
    }

    string expand(string s, int i, int j) {
        while(j < s.size() && i >= 0 && s[i] == s[j]) {
            i--;
            j++;
        }
        // Add 1 to i and subtract 1 from j because the range is expanded by 1 on each side before it ends
        return s.substr(i+1, j-i-1);
    }
};