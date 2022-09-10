// Runtime: 41 ms (Top 23.63%) | Memory: 19.6 MB (Top 14.15%)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Initialize sol and cnt to store the solution and its frequency for respective iterations...
        int sol = 0, cnt = 0;
        // For every element i in the array...
        for(int i = 0; i < nums.size(); i++ ) {
            // If cnt is equal to zero, update sol as sol = i
            if(cnt == 0){
                sol = nums[i];
                cnt = 1;
            }
            // If i is equal to candidate, increment cnt...
            else if(sol == nums[i]){
                cnt++;
            }
            // Otherwise, decrement cnt...
            else{
                cnt--;
            }
        }
        // Return & print the solution...
        return sol;
    }
};