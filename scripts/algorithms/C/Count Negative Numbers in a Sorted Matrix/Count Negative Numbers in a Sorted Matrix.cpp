class Solution {
public:
	int countNegatives(vector<vector<int>>& grid) {
        int ans = 0; for (auto hehe : grid) for (int i : hehe) if (i < 0) ans++; return ans;
    }
};
