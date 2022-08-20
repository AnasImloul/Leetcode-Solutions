// Runtime: 47 ms (Top 14.86%) | Memory: 18 MB (Top 20.20%)

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