// Runtime: 7 ms (Top 76.74%) | Memory: 12.1 MB (Top 99.93%)
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