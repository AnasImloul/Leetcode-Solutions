class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int n = coins.size();
        int ans = 1;
        for(int i = 0; i < n; i++) {
            if(coins[i] > ans) return ans;
            ans += coins[i]; 
        }
        return ans;
    }
};