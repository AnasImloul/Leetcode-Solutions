// Runtime: 214 ms (Top 86.81%) | Memory: 114.10 MB (Top 87.34%)

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(), banned.end());
        int ans = 0;
        for(int i = 1, j = 0; i <= n; ++i){
            if((j == banned.size() || i < banned[j] ) && maxSum- i >= 0) { 
                ans++; maxSum -= i; 
            }else{
                while(j < banned.size() && i >= banned[j]) j++;
            }
        }
        return ans;
    }
};

