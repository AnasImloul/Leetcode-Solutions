class Solution {
 public:
  vector<int> fallingSquares(vector<vector<int>>& positions) {
    vector<int> ans;
    map<int, pair<int, int>> h;
    int max_height = 0;
    for (int i = 0; i < positions.size(); ++i) {
      int left = positions[i][0];
      int right = left + positions[i][1];
      int height = 0;
      for (auto& it : h) {
        if (it.first >= right) break;
        if (it.second.first > left) {
          height = max(height, it.second.second);
        }
      }
      height += positions[i][1];
      h[left] = {right, height};
      max_height = max(max_height, height);
      ans.push_back(max_height);
    }
    return ans;
  }
};
