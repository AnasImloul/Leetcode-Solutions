// Runtime: 89 ms (Top 70.91%) | Memory: 63.80 MB (Top 73.86%)

class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1&&(k&1)){
            return -1;
        }
        int mxm=-1;
        for(int i=0;i<n&&i<k-1;i++){
            mxm=max(mxm,nums[i]);
        }
        if(k<n){
            mxm=max(mxm,nums[k]);
        }
        return mxm;
    }
};
