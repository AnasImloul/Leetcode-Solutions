// Runtime: 816 ms (Top 24.26%) | Memory: 139.4 MB (Top 31.76%)
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<array<int, 2>> que;
        int ret = nums[0], curr;
        que.push({nums[0], 0});
        for (int i = 1; i < nums.size(); i++) {
            while (!que.empty() && que.top()[1] < i - k) {
                que.pop();
            }
            curr = max(0, que.top()[0]) + nums[i];
            ret = max(ret, curr);
            que.push({curr, i});
        }
        return ret;
    }
};