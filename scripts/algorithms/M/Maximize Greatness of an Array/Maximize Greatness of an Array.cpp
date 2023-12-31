// Runtime: 97 ms (Top 46.27%) | Memory: 76.00 MB (Top 96.77%)

class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        int ind=n-1;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[ind])
            {
                ind--;
                ans++;
            }
        }
        return ans;
    }
};
