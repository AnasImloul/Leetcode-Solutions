class Solution {
 public:
  bool isRectangleCover(vector<vector<int>>& rectangles) {
    SegmentTree<STMax> st(2e5 + 1);
    sort(rectangles.begin(), rectangles.end(), [](auto& lhs, auto& rhs) -> bool {
      if (lhs[1] != rhs[1]) return lhs[1] < rhs[1];
      return lhs[0] < rhs[0];
    });

    int min_x = rectangles[0][0];
    int min_y = rectangles[0][1];
    int max_a = rectangles[0][2];
    int max_b = rectangles[0][3];
    long long sum = 1ll * (max_a - min_x) * (max_b - min_y);
    st.update(min_x + 1e5 + 1, max_a + 1e5, max_b);
    for (int i = 1; i < rectangles.size(); ++i) {
      if (rectangles[i][0] < min_x) return false;
      int max_height = st.query(rectangles[i][0] + 1e5 + 1, rectangles[i][2] + 1e5);
      if (max_height > rectangles[i][1]) return false;
      max_a = max(max_a, rectangles[i][2]);
      max_b = max(max_b, rectangles[i][3]);
      sum += 1ll * (rectangles[i][2] - rectangles[i][0]) * (rectangles[i][3] - rectangles[i][1]);
      st.update(rectangles[i][0] + 1e5 + 1, rectangles[i][2] + 1e5, rectangles[i][3]);
    }
    return sum == 1ll * (max_a - min_x) * (max_b - min_y);
  }
};
