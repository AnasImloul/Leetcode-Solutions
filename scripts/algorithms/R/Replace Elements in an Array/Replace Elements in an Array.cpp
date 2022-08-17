int m[1000001];
class Solution {
public:
vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
    for (int i = 0; i < nums.size(); ++i)
        m[nums[i]] = i;
    for (auto &op : operations) {
        nums[m[op[0]]] = op[1];
        m[op[1]] = m[op[0]];
    }
    return nums;
}
};
