// Runtime: 51 ms (Top 82.87%) | Memory: 25.5 MB (Top 58.45%)
class Solution {
public:
    int findShortestSubArray(vector<int>& nums)
    {
        unordered_map<int,int> cnt,first;
        int deg=0,ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(cnt[nums[i]]==0)
                first[nums[i]]=i;
            cnt[nums[i]]++;
            if(cnt[nums[i]]>deg)
            {
                ans=i-first[nums[i]]+1;
                deg=cnt[nums[i]];
            }
            else if(cnt[nums[i]]==deg)
            {
                ans=min(ans,i-first[nums[i]]+1);
            }

        }
        return ans;

    }
};
//if you like the solution plz upvote.