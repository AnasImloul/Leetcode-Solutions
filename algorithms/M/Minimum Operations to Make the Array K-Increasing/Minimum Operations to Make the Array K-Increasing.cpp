class Solution {
public:
      int getlis(vector<int>&a) {
            vector<int>v;
            for (auto p : a) {
                  auto it = upper_bound(v.begin(), v.end(), p);
                  if (it == v.end()) {
                        v.push_back(p);
                  }
                  else {
                        *it = p;
                  }
            }
            return v.size();
      }
      int kIncreasing(vector<int>& arr, int k) {
            const int n = arr.size();
            vector<vector<int>>v(k);
            for (int i = 0; i < n; i++) {
                  v[i % k].push_back(arr[i]);
            }

            int ans = 0;
            for (int i = 0; i < k; i++) {
                  int lis = getlis(v[i]);
                  ans += v[i].size() - lis;
            }
            return ans;
      }
};
