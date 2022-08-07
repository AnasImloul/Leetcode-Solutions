class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int sum=0,n=nums.size();
        sort(nums.begin(),nums.end());
        int median=nums[n/2];
        for(int i=0;i<n;i++)
            sum+=abs(nums[i]-median);     
    return sum; 
    }
};
