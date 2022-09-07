// Runtime: 7 ms (Top 74.55%) | Memory: 9.6 MB (Top 96.76%)
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int size = nums.size();
        int i = 0, j =0;
        for(i=0,j=n; i<n && j<size; i++, j++){
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
        }
        return ans;
    }
};