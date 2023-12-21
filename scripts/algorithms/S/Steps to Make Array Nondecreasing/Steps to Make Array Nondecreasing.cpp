// Runtime: 147 ms (Top 51.38%) | Memory: 87.00 MB (Top 65.23%)

class Solution {
public:
    int totalSteps(vector<int>& nums) 
    {
        int n=nums.size(),i,ans=0,cnt,prev;
        stack <pair<int,int>> st;
        st.push({nums[n-1],0});
        for(i=n-2;i>=0;i--)
        {
            cnt=0;
            while(!st.empty() && nums[i]>st.top().first)
            {
                cnt=max(cnt+1,st.top().second);
                st.pop();
            }
            ans=max(ans,cnt);
            st.push({nums[i],cnt});
        }
        return ans;
    }
};
