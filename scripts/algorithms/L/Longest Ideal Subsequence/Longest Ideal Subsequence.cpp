// Runtime: 77 ms (Top 85.46%) | Memory: 10.3 MB (Top 60.17%)
class Solution {
public:
    int longestIdealString(string s, int k) {
        int DP[26] = {0}, ans = 1;

        for (char &ch: s) {
            int i = ch - 'a';
            DP[i] = DP[i] + 1;

            for (int j = max(0, i - k); j <= min(25, i + k); j++)
                if (j != i)
                    DP[i] = max(DP[i], DP[j] + 1);

            ans = max(ans, DP[i]);
        }

        return ans;
    }
};