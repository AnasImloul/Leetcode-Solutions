// Runtime: 348 ms (Top 90.22%) | Memory: 108.9 MB (Top 40.22%)
class MajorityChecker {
public:
    MajorityChecker(vector<int>& arr) {
        this->arr = arr;
        map<int, int> cnt;
        for (auto& v: arr) {
            cnt[v]++;
        }
        val_idx = vector<int>(20001, -1);
        for (auto it = cnt.begin(); it != cnt.end(); ++it) {
            if (it->second >= 250) {
                val_idx[it->first] = elems.size();
                elems.push_back(it->first);
            }
        }
        n = elems.size();
        pre = vector<vector<int>>(n, vector<int>(arr.size(), 0));
        if (val_idx[arr[0]] != -1)
            pre[val_idx[arr[0]]][0]++;
        for (int i = 1; i < arr.size(); ++i) {
            for (int j = 0; j < n; ++j) {
                pre[j][i] = pre[j][i-1];
            }
            if (val_idx[arr[i]] != -1)
                pre[val_idx[arr[i]]][i]++;
        }
    }

    int query(int left, int right, int threshold) {
        int width = right - left + 1;
        if (width < 500) {
            map<int, int> cnt;
            int most_frequent = 0;
            int most_frequent_val;
            while (left <= right) {
                if (++cnt[arr[left++]] > most_frequent) {
                    most_frequent = cnt[arr[left - 1]];
                    most_frequent_val = arr[left - 1];
                }
                // early end condition, there are not enough elements left
                if (right + most_frequent + 1 < threshold + left) return -1;
            }
            return most_frequent >= threshold ? most_frequent_val : -1;
        }

        for (int i = 0; i < n; ++i) {
            if (pre[i][right] - (left - 1 >= 0 ? pre[i][left - 1] : 0) >= threshold) {
                return elems[i];
            }
        }
        return -1;
    }

private:
    vector<int> arr;
    vector<int> elems;
    vector<int> val_idx;
    int n;
    vector<vector<int>> pre;
};