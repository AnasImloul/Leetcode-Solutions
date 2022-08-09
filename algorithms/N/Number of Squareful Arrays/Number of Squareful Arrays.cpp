class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) {
     sort(nums.begin(),nums.end());
        int ans=0;
        solve(nums,0,ans);
        return ans;
    }
    void solve(vector<int>nums,int idx,int &ans){
        if(idx>=nums.size())
        {
            ++ans;
        }
        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[idx])
                continue;
            swap(nums[i],nums[idx]);
            if(idx==0 || ( idx>0 && isSquare(nums[idx]+nums[idx-1])))
                solve(nums,idx+1,ans);
        }
    }
    bool isSquare(int n){
        int temp=sqrt(n);
        return temp*temp==n;
    }
};
