class Solution {
public:
    int beautySum(string s) {
        int n = s.length(), sum = 0;
        for (int i = 0; i < n - 1; i++) {
            vector<int> dp(26, 0);
            dp[s[i] - 'a']++;
            for (int j = i + 1; j < n; j++) {
                dp[s[j] - 'a']++;
                int minNum = INT_MAX, maxNum = INT_MIN;
                for (int k = 0; k < 26; k++) {
                    if (dp[k]) minNum = min(minNum, dp[k]);
                    if (dp[k]) maxNum = max(maxNum, dp[k]);
                }
                sum = sum + (maxNum - minNum);
            }
        }
        return sum;
    }
};
