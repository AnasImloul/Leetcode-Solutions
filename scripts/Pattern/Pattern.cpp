class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // Initialise a empty stack "s"...
        stack<int> s;
        // To keep track of minimum element...
        int min = INT_MIN;
        // Run a Loop from last to first index...
        for (int i = nums.size() - 1; i >= 0; i--) {
            // If min is greater than nums[i], return true...
            if (nums[i] < min)
                return true;
            // If stack is not empty &  nums[i] is greater than the top element of stack, then pop the element...
            while (!s.empty() && nums[i] > s.top()) {
                min = s.top();
                s.pop();
            }
            // Otherwise, push nums[i] into stack...
            s.push(nums[i]);
        }
        // If the condition is not satisfied, return false.
        return false;
    }
};
