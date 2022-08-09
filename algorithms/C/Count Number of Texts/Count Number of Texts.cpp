class Solution {
public:
    int mod = 1e9+7;
    int solve(string &str, int idx) {
        if(idx == str.length()) return 1;
        int maxKeyPress = (str[idx] == '7' || str[idx] == '9') ? 4 : 3;
        long long currIndex = idx, pressFrequency = 1, ans = 0;
        while(pressFrequency <= maxKeyPress && str[currIndex] == str[idx]) {
            ++currIndex;
            ++pressFrequency;
            ans += solve(str, currIndex) % mod;
        }
        return ans%mod;
    }
    int countTexts(string pressedKeys) {
        return solve(pressedKeys, 0) % mod;
    }
};
