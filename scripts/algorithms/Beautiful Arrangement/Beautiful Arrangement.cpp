class Solution {
public:
    int ans = 0;
    bool isBeautiful(vector<int> &v) {
        int i = v.size() - 1;
        if (v[i] % (i + 1) == 0 || (i + 1) % v[i] == 0) return true;
        return false;
    }

    void solve(int n, vector<int> &p, vector<bool> &seen) {
        if (p.size() == n) {
            ans++;
            return;
        }
        for (int i = 1; i <= n; i++) {

            if (seen[i]) continue;
            p.push_back(i);

            if (isBeautiful(p)) {
                seen[i] = true;
                solve(n, p, seen);
                seen[i] = false;
            }
            p.pop_back();
        }
    }
    int countArrangement(int n) {

        vector<int> p;
        vector<bool> seen(n + 1, false);
        solve(n, p, seen);

        return ans;
    }
};
