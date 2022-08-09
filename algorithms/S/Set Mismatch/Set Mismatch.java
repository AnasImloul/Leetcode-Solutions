class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        unordered_map<int,int> m;
        int p,q;
        for(auto &x:nums)
        {
            m[x]++;
            if(m[x]==2)
            {
                p=x;
                break;
            }
        }
        int n=nums.size();
        q=(n*(n+1))/2-accumulate(nums.begin(),nums.end(),0)+p;
        return {p,q};
        
    }
};
// if you like the solution plz upvote.