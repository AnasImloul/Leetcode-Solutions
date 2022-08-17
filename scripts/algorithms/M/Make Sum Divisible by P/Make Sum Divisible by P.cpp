class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        int sm=0;
        int ans=INT_MAX,cur=INT_MAX;
        for(int it:nums) sm=(sm+it)%p;
        if(sm==0)
            return 0;
        unordered_map<long long,int> mp={{0,-1}};
        long long pre=0;
        for(int i=0;i<n;i++)
        {
            pre=(pre+nums[i])%p;
            mp[pre]=i;
            if(mp.count((pre-sm+p)%p)>0)
                cur=i-mp[(pre-sm+p)%p];
            ans=min(ans,cur);
        }
        if(ans==INT_MAX||ans==n)
            return -1;
        else
            return ans;
    }
};
