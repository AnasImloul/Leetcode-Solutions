class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,h=nums.size()-1;
        while(l<h){
            int m=l+(h-l)/2;
            if(nums[m]<nums[h]) h=m;
            else if(nums[m]>nums[h]) l=m+1;
            else h--;
        }
        return nums[h];
    }
};