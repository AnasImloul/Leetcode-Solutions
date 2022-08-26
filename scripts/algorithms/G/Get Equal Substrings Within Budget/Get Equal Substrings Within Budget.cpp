// Runtime: 9 ms (Top 64.85%) | Memory: 7.7 MB (Top 51.71%)
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int l = 0, r = 0, currCost = 0, n = s.length(), maxLen = 0;

        while(r < n) {
            currCost += abs(s[r] - t[r]);
            r++;

            while(currCost > maxCost) {
                currCost -= abs(s[l] - t[l]);
                l++;
            }

            maxLen = max(r - l, maxLen);
        }

        return maxLen;
    }
};