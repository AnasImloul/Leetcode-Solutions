class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums)
    {
        vector<int> v;
        vector<int> odd;
        if(nums.size()==1)
        {
            return nums;
        }
        for(auto it : nums)
        {
            if(it%2==0)
            {
                v.push_back(it);
            }
            else
            {
                   odd.push_back(it);
            }
            
        }

        for(auto i : odd)
        {
            v.push_back(i);
        }
        return v;
    }
};