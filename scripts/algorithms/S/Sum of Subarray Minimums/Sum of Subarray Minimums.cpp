typedef long long ll;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int modval = 1e9 + 7;
        int n = arr.size(), ans = 0;
        vector<int> stck;
        vector<ll> res(n);
        for (int i = 0; i < n; i++) {
            while (not stck.empty() and arr[i] <= arr[stck.back()]) stck.pop_back();
            res[i] = arr[i] * (i - ((stck.empty()) ? -1 : stck.back()));
            if (not stck.empty()) res[i] += res[stck.back()];
            res[i] %= modval;
            stck.push_back(i);
            cout << res[i] << "\n";
        }
        for (ll i : res) ans = (ans + i) % modval;
        return ans;
    }
};