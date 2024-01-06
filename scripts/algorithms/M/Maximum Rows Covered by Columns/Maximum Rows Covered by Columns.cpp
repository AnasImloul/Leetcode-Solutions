// Runtime: 0 ms (Top 100.0%) | Memory: 8.80 MB (Top 76.3%)

class Solution {
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int m = mat.size(), n = mat[0].size();
        vector<int> nums;
        for(int i = 0; i < m; i++) {
            string str;
            for(int j = 0; j < n; j++) {
                str += (mat[i][j] + '0');
            }
            int number = stoi(str, nullptr, 2);
            nums.push_back(number);
        }
        int range = 1 << n;
        int ans = 0;
        for(int i = 0; i < range; i++) {
            int count = 0;
            if(__builtin_popcount(i) == cols) {
                for(auto it : nums) {
                    if((it | i) == i)
                        count++;
                }
            }
            ans = max(ans, count);
        }
        return ans;
    }
};
