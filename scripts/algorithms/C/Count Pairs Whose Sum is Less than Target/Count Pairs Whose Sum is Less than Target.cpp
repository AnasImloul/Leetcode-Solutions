// Runtime: 8 ms (Top 26.89%) | Memory: 20.80 MB (Top 32.76%)

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); 
        
        int count = 0;
        int left = 0, right = n - 1;
        
        while (left < right) {
            if (nums[left] + nums[right] < target) {
              
                count += right - left;
                left++;
            } else {
             
                right--;
            }
        }
        
        return count;
    }
};
