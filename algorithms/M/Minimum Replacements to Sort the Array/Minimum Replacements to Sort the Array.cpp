class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long res=0;
        int n=nums.size();
        int mxm=nums[n-1];
        long long val;
        for(int i=n-2;i>=0;i--)
        {
            // minimum no. of elemetns nums[i] is divided such that every number is less than mxm and minimum is maximized
            val= ceil(nums[i]/(double)mxm); 
            
            // no. of steps is val-1
            res+=(val-1);
            
            // the new maximized minimum value 
            val=nums[i]/val;
            mxm= val;
        }
        return res;
    }
};
