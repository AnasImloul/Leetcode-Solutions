// Runtime: 44 ms (Top 18.57%) | Memory: 9.30 MB (Top 45.24%)

class Solution {
public:
    int minimumPartition(string s, int k) {
        int i = 0, c = 0, j = 0;
        // i - left pointer
        // j - right pointer
        while (j < s.length()) {
            while (j < s.length() && stol(s.substr(i, j-i+1)) <= k) {
                j++;
            }
            c++;
            if (i == j) {
                return -1;
            }
            i = j;
        }
        return c;
    }
};

