class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int ans=-1, sz=nums.size();
        unordered_map<int,int>mp;
        for(auto & i:nums){
            string s=to_string(i);
            int sum=0;
            for(auto & ch:s)
                sum+=(ch-'0');
            if(mp.count(sum))
                ans=max(ans,i+mp[sum]);
            mp[sum]=max(i,mp[sum]);
        }
        return ans;
    }
};
