class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        {
            if(nums[0]==0)
                return {1};
            else
                return {0};
        }
        int one=0,zero=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
                one++;
        }
        if(nums[0]==0)
            zero++;
        vector<int> v;
        v.push_back(one);
        int ans=one;
        if(nums[0]==1)
            one--;
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]==1)
            {
                v.push_back(zero+one);
                one--;
            }
            else
            {
                v.push_back(zero+one);
                zero++;
            }
            ans=max(ans,zero+one);   
        }
        
        v.push_back(zero);
        vector<int> res;
        for(int i=0;i<=n;i++)
        {
            // cout<<v[i]<<" ";
            if(v[i]==ans)
                res.push_back(i);
        }
        return res;
    }
};