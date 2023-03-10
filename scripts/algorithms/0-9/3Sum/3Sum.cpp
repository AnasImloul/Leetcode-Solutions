class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < nums.size() - 2; i++)
        {
            if(i > 0 && (nums[i] == nums[i - 1]))
                continue;

            int left_index = i + 1;
            int right_index = nums.size() - 1;

            while(left_index < right_index)
            {
                int threesome = nums[i] + nums[left_index] + nums[right_index];
                if (threesome > 0)
                    right_index--;
                else if (threesome < 0)
                    left_index++;
                else
                {
                    ans.push_back({nums[i], nums[left_index], nums[right_index]});
                    
                    while(((left_index < right_index) && nums[left_index] == nums[left_index + 1]))
                        left_index++;
                    left_index ++;

                }

            }
            
        }

        return ans;
    }
}; 