// Runtime: 62 ms (Top 31.95%) | Memory: 7.3 MB (Top 97.57%)
class Solution {
 public:
  int dp[8][(1 << 8) - 1];
  int maxStudents(vector<vector<char>>& seats) {
    memset(dp, -1, sizeof(dp));
    return helper(seats, 0, 0);
  }
  int helper(vector<vector<char>>& seats, int prevAllocation, int idx) {
    if (idx == seats.size()) return 0;
    int sz = seats[0].size(), masks = ((1 << sz) - 1), maxi = 0;
      // masks is for iterating over all subsets
    if (dp[idx][prevAllocation] != -1) return dp[idx][prevAllocation];
    while (masks >= 0) {
      int curAllocation = 0, cnt = 0;
      for (int i = 0; i < sz; i++) {
        if (seats[idx][i] != '#' && masks >> i & 1) {
          int ul = i - 1, ur = i + 1;
          bool canPlace = true;
          if (ul >= 0)
            if (prevAllocation >> ul & 1 || curAllocation >> ul & 1)
              canPlace = false;
          if (ur < sz)
            if (prevAllocation >> ur & 1 || curAllocation >> ur & 1)
              canPlace = false;
          if (canPlace) {
            curAllocation |= 1 << i;
            cnt++;
          }
        }
      }
      maxi = max(maxi, cnt + helper(seats, curAllocation, idx + 1));
      masks--;
    }
    dp[idx][prevAllocation] = maxi;
    return maxi;
  }
};