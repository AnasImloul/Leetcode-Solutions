class Solution {
  int bin_search_left(vector<vector<int>>& a, vector<int>& new_interval) {
    int l = -1, r = a.size();
    while (r - l > 1) {
      int m = (r + l) / 2;
      if (a[m][1] < new_interval[0]) {
        l = m;
      } else {
        r = m;
      }
    }
    return r == a.size() ? -1 : r;
  }
  
  int bin_search_right(vector<vector<int>>& a, vector<int>& new_interval) {
    int l = -1, r = a.size();
    while (r - l > 1) {
      int m = (r + l) / 2;
      if (a[m][0] <= new_interval[1]) {
        l = m;
      } else {
        r = m;
      }
    }
    return l;
  }
  
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int left = bin_search_left(intervals, newInterval);
    if (left == -1) {
      intervals.push_back(newInterval);
      return intervals;
    }

    int right = bin_search_right(intervals, newInterval);
    if (right == -1) {
      vector<vector<int>> result {newInterval};
      result.insert(result.end(), intervals.begin(), intervals.end());
      return result;
    }
    
    vector<vector<int>> result;
    for (int i = 0; i < left; ++i) {
      result.push_back(intervals[i]);
    }
    
    int new_left = std::min(newInterval[0], intervals[left][0]);
    int new_right = std::max(newInterval[1], intervals[right][1]);
    result.push_back(std::vector<int>{new_left, new_right});
    
    for (int i = right + 1; i < intervals.size(); ++i) {
      result.push_back(intervals[i]);
    }
    return result;
  }
};
