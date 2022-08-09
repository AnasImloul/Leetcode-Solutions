class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int sum=0;
        vector<int> minV,maxV;
        int maximum=0;
        int minimum=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            maximum=max(maximum,nums[i]);
            maxV.push_back(maximum);
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
              minimum=min(minimum,nums[i]);
            minV.push_back(minimum);
        }
        for(int i=1;i<nums.size()-1;i++)
        {
           if((maxV[i-1]<nums[i] && minV[minV.size()-i-2]>nums[i]))
              sum+=2;
           else if(nums[i-1]<nums[i] && nums[i+1]>nums[i])
               sum+=1;
        }
      return sum;  
    }
};
