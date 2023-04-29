class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
           int maxWealth = 0;
        for (auto account : accounts) {
            int currentSum = 0;
            for (int x : account) currentSum += x;
            if (currentSum > maxWealth) maxWealth = currentSum;
        }
        return maxWealth;
    }
};


