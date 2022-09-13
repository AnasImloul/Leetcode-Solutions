// Runtime: 17 ms (Top 6.16%) | Memory: 10.7 MB (Top 79.60%)
//Solution 01:
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        int i = n-1, ans = 0;

        if(n <= 2){
            for(auto x: cost)
                ans += x;
            return ans;
        }

        sort(cost.begin(), cost.end());

        while(i>=1){
            ans += cost[i] + cost[i-1];
            if(i-1 == 0 || i-1 == 1) return ans;
            i = i-3;
        }
        ans += cost[0];

        return ans;
    }
};