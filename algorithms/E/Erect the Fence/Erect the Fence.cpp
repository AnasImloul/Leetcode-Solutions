class Solution {
 public:
  vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
    if (trees.size() <= 1) return trees;

    int origin = 0;
    for (int i = 0; i < trees.size(); ++i) {
      if (trees[origin][1] > trees[i][1] || trees[origin][1] == trees[i][1] && trees[origin][0] > trees[i][0]) {
        origin = i;
      }
    }
    swap(trees[0], trees[origin]);
    sort(trees.begin() + 1, trees.end(), [&](const vector<int>& lhs, const vector<int>& rhs) -> bool {
      int result = cross(trees[0], lhs, rhs);
      if (result != 0) return result > 0;
      return norm(trees[0], lhs) < norm(trees[0], rhs);
    });

    // deal with cases that the last k points are on one line
    int pos = trees.size() - 2;
    while (pos > 0 && cross(trees[0], trees.back(), trees[pos]) == 0) {
      --pos;
    }
    reverse(trees.begin() + pos + 1, trees.end());

    vector<vector<int>> ans = {trees[0], trees[1]};
    for (int i = 2; i < trees.size(); ++i) {
      int cross_result = cross(ans[ans.size() - 2], ans[ans.size() - 1], trees[i]);
      while (cross_result < 0) {
        ans.pop_back();
        cross_result = cross(ans[ans.size() - 2], ans[ans.size() - 1], trees[i]);
      }
      ans.push_back(trees[i]);
    }
    return ans;
  }

 private:
  inline double norm(const vector<int>& o, const vector<int>& x) {
    int xx = x[0] - o[0];
    int yy = x[1] - o[1];
    return sqrt(xx * xx + yy * yy);
  }

  inline int cross(const vector<int>& x, const vector<int>& y, const vector<int>& z) {
    return (y[0] - x[0]) * (z[1] - y[1]) - (y[1] - x[1]) * (z[0] - y[0]);
  }
};
