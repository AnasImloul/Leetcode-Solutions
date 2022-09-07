// Runtime: 66 ms (Top 61.05%) | Memory: 27.8 MB (Top 36.29%)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        int min1 = INT_MAX , min2 = INT_MAX; // Both have the maximum value that is +infinte
        int max1 = INT_MIN, max2 = INT_MIN , max3 = INT_MIN; //All these have the minimum value that is -infinte

        //now finding all these value above declared.
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] > max1 )
            {
                max3 = max2 ;
                max2 = max1;
                max1 = nums[i];

            }
            else if(nums[i] > max2)
            {
                max3 = max2 ;
                max2 = nums[i] ;

            }
            else if(nums[i] > max3)
            {
                max3 = nums[i] ;

            }

            if(nums[i] < min1)
            {
                min2 = min1 ;
                min1 = nums[i] ;

            }
            else if(nums[i] < min2)
            {
                min2 = nums[i];

            }
        }
        return max(min1*min2*max1 , max1*max2*max3);
    }
};