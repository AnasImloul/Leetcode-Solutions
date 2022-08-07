class Solution {
    unordered_map<int,vector<int>> itemIndicies;
public:
    Solution(vector<int>& nums)
    {
        srand(time(NULL));
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (itemIndicies.find(nums[i]) == itemIndicies.end())
                itemIndicies[nums[i]] = {i};
            else
                itemIndicies[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int size = itemIndicies[target].size();
        int randomValue = rand() % size;
        return itemIndicies[target][randomValue];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
