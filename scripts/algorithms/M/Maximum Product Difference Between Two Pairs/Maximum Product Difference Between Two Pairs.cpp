// Runtime: 60 ms (Top 31.22%) | Memory: 20.4 MB (Top 66.96%)
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        //we have to return the result of
        // (firstMax*secondMax) - (firstMin*secondMin)
        int max1=INT_MIN;
        int max2=INT_MIN;
        int min1=INT_MAX;
        int min2=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {

            if(nums[i]>max1)
            {
                //assign the second max to max2
                max2=max1;
                max1=nums[i];
            }
            else if(nums[i]>max2)
            {
                //it can become second max
                max2= nums[i];
            }

            //check for the minimum
            if(nums[i]<min1)
            {
                //it can become first minimum
                min2=min1;
                min1=nums[i];
            }
            else if(nums[i]<min2)
            {
                //it can become second minimum
                min2=nums[i];
            }
        }
        return (max1*max2)- (min1*min2);
    }
};