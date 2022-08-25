// Runtime: 415 ms (Top 35.30%) | Memory: 10 MB (Top 96.80%)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Two for loops for selecting two numbers and check sum equal to target or not

        for(int i = 0;i < nums.size();i++)
        {
            for(int j = i + 1;j < nums.size();j++)
            {
                // j = i + 1; no need to check back elements it covers in i;
                if ((nums[i] + nums[j]) == target){
                    // Check sum == target or not
                    return{i,j};
                }

            }
        }
        return {};
    }
};