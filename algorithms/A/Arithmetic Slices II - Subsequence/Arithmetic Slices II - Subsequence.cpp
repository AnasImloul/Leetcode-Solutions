class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size(),ans=0;
        unordered_map<long long, unordered_map<int,int>> ma;   // [diff, [index, count]]
        unordered_map<int,int> k;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                long long diff= (long long)nums[i]-(long long)nums[j];
                if(ma.find(diff)==ma.end())
                    ma[diff]= k;
                if(ma[diff].find(j)==ma[diff].end())
                    ma[diff][j]=0;
                ma[diff][i] += ma[diff][j] + 1;
                ans += ma[diff][j];
            }
        }
        return ans;
    }
};
