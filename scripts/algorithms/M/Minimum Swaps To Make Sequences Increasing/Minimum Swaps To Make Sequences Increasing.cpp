// Runtime: 370 ms (Top 57.12%) | Memory: 107.8 MB (Top 57.19%)
class Solution {
public:
    int n;
    vector<int>nums1,nums2;
    int dp[200005][3];
    int find(int index,int sp)
    {
        if(index==n)
        {
            return 0;
        }
        if(dp[index][sp]!=-1)
        {
            return dp[index][sp];
        }
        int prev1=nums1[index-1];
        int prev2=nums2[index-1];
        int ans=1e8;
        if(sp)
        {
            swap(prev1,prev2);
        }
        if(prev1<nums1[index]&&prev2<nums2[index])
        {
            ans=min(ans,find(index+1,0));
        }
        if(prev1<nums2[index]&&prev2<nums1[index])
        {
            ans=min(ans,1+find(index+1,1));
        }
        return dp[index][sp]=ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2)
    {
        memset(dp,-1,sizeof(dp));
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        n=nums1.size();
        this->nums1=nums1;
        this->nums2=nums2;
        return find(1,0);
    }
};