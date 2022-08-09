class BIT {
 public:
  BIT(int capacity) : nodes(capacity + 1, 0) {}
  BIT(const vector<int>& nums) : nodes(nums.size() + 1, 0) {
    for (int i = 0; i < nums.size(); ++i) {
      update(i + 1, nums[i]);
    }
  }

  void update(int idx, int val) {
    for (int i = idx; i < nodes.size(); i += i & -i) {
      nodes[i] += val;
    }
  }

  int query(int idx) {
    int ans = 0;
    for (int i = idx; i > 0; i -= i & -i) {
      ans += nodes[i];
    }
    return ans;
  }

 private:
  vector<int> nodes;
};

class Solution {
 public:
  int maxChunksToSorted(vector<int>& arr) {
    int n = arr.size();
    BIT bit(n);
    unordered_map<int, int> h;
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < n; ++i) {
      if (i == 0 || sorted[i - 1] != sorted[i]) h[sorted[i]] = i + 1;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      bit.update(h[arr[i]], 1);
      ++h[arr[i]];
      if (bit.query(i + 1) == i + 1) ans += 1;
    }
    return ans;
  }
};
