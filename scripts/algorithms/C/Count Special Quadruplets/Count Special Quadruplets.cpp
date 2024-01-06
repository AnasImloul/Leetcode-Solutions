// Runtime: 15 ms (Top 91.46%) | Memory: 13.90 MB (Top 18.59%)

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int res = 0;
        int len = nums.size();
        
        unordered_map<int, int> count;
        count[nums[len-1] - nums[len-2]] = 1;
        
        for (int b = len - 3; b >= 1; b--) {
            for (int a = b - 1; a >= 0; a--) {
                res += count[nums[a] + nums[b]];
            }
            
            for (int x = len - 1; x > b; x--) {
                count[nums[x] - nums[b]]++;
            }
        }
        
        return res;
    }
};
