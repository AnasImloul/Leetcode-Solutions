class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        /*
            1. reorder nums to keep 1 in index 1, 2 in index 2 ... 
                 3,4,-1,1 -> 1,-1,3,4
                 1,2,0 -> 1,2,0
                 7,8,9,11,12 -> 7,8,9,11,12
                algorithm: keep swapping if num in [1, N], if the two nums doesn't equal
            2. the one missing in expected place is the missing one
        */
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1] ) {
                swap(nums[nums[i] - 1], nums[i]);
            } 
        }
        
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        // if it is already ordered, e.g. [1,2], [1], [1,2,3]
        return n + 1;
        
    }
};
