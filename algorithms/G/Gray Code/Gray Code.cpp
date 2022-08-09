class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> dp = {0,1};
        int cnt = 1;
        for(int i = 2; i < n+1; i++) {
            int mod = pow(2, cnt);
            int index = dp.size()-1;
            while(index >= 0) {
                dp.push_back(dp[index] + mod);
                index--;
            }
            cnt++;
        }
        return dp;
    }
};