class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end()); //sort nums in increasing order
        int count=0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] > 0) //first smallest non-zero element
            {
                int x = nums[i];
                count++;
                for(int j=i; j<nums.size(); j++) //substract x from all elements greater than it.
                {
                    nums[j] = nums[j]-x;
                }

            }
        }
        return count;
        
    }
};
