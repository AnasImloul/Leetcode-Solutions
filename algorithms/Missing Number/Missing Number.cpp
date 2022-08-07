class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int n=nums.size();
        long sum=n*(n+1)/2;
        long temp=0;
        for(int i=0;i<n;i++)
        {
            temp+=nums[i];
            
        }
        return sum-temp;
    }
};
