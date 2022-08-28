// Runtime: 431 ms (Top 37.35%) | Memory: 110.7 MB (Top 26.25%)
class Solution {
public:
    int totalStrength(vector<int>& strength) {
        int n = strength.size();
        long long ans = 0, mod = 1e9 + 7;
        vector<long long> prefix(n + 1, 0), iprefix(n + 1, 0), isuffix(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            prefix[i] = prefix[i - 1] + strength[i - 1];
            iprefix[i] = iprefix[i - 1] + (long long)i * (long long)strength[i - 1];
            isuffix[n - i] = isuffix[n - i + 1] + (long long)i * (long long)strength[n - i];
        }
        vector<int> l(n, -1), r(n, -1);
        stack<int> sl, sr;
        for (int i = 0; i < n; i++)
        {
            while (!sl.empty() && strength[sl.top()] > strength[i])
                sl.pop();
            if (sl.empty())
                l[i] = 0;
            else
                l[i] = sl.top() + 1;
            sl.push(i);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            while (!sr.empty() && strength[sr.top()] >= strength[i])
                sr.pop();
            if (sr.empty())
                r[i] = n - 1;
            else
                r[i] = sr.top() - 1;
            sr.push(i);
        }
        for (int i = 0; i < n; i++)
        {
            int lb = l[i], rb = r[i];
            long long ln = i - lb + 1, rn = rb - i + 1, mv = strength[i], lsv = 0, rsv = 0, sv = 0;
            lsv = (iprefix[i] - iprefix[lb] - lb * (prefix[i] - prefix[lb]) + mod) % mod * rn % mod;
            rsv = (isuffix[i + 1] - isuffix[rb + 1] - (n - rb - 1) * (prefix[rb + 1] - prefix[i + 1]) + mod) % mod * ln % mod;
            sv = (lsv + rsv + (ln * rn) * (long long)strength[i]) % mod;
            ans = (ans + sv * mv) % mod;
        }
        return ans;
    }
};