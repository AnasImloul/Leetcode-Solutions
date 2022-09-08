// Runtime: 175 ms (Top 32.17%) | Memory: 41.7 MB (Top 33.74%)
class Solution {
public:
    int findLHS(vector<int>& nums)
    {
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        int ans=0;
        int x=-1,y=0;
        for(auto i=m.begin();i!=m.end();i++)
        {
            if(i->first-x==1)
            {
                ans=max(ans,y+i->second);
            }
            x=i->first;
            y=i->second;
        }
        return ans;

    }
};
//if you like the solution plz upvote.