// Runtime: 110 ms (Top 86.96%) | Memory: 59.50 MB (Top 24.88%)

class Solution {
public:
    bool calc(vector<int>& nums, int k,int mid)
    {
        int i=0,n=nums.size();
        while(i<n)
        {
            if(nums[i]<=mid)k--, i+=2;
            
            else i++;
            
            if(k == 0) return true;
        }
        return k == 0;
    }
    int minCapability(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int lo = 0,hi = 1e9+1;
        while(lo<hi)
        {
            int mid = (lo+hi)/2;
            if(calc(nums, k, mid)) hi=mid;
            else lo=mid+1;
        }
        return lo;
    }
};
