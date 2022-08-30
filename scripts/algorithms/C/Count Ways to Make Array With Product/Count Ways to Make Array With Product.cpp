// Runtime: 259 ms (Top 58.24%) | Memory: 69 MB (Top 25.27%)
#define MOD 1000000007

// calculating combinatorics
long long comb(int n, int m) {
    static long long c[20001][10001] = {0};
    if (c[n][m] != 0)
        return c[n][m];
    long long res;
    if (m == 0 || m == n)
        res = 1;
    else
        res = (comb(n - 1, m) + comb(n - 1, m - 1)) % MOD;
    c[n][m] = res;
    return res;
}

class Solution {
public:
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        vector<int> factors;
        vector<int> res;
        for (int i = 0; i < queries.size(); i++) {
            // counting numbers of distinct prime factors
            // note that numbers within 10000 have at most 1 prime factor over 100
            // if we loop to queries[i][1] here we will get a TLE since one loop grows from 100 to 10000 here
            factors.clear();
            for (int j = 2; j <= 97; j++) {
                if (queries[i][1] % j == 0) {
                    int count = 0;
                    while (queries[i][1] % j == 0) {
                        count++;
                        queries[i][1] /= j;
                    }
                    factors.push_back(count);
                }
            }
            if (queries[i][1] != 1)
                factors.push_back(1);

            // calculate ways
            int tmp = 1;
            for (int f : factors) {
                tmp = (tmp * comb(f + queries[i][0] - 1, queries[i][0] - 1)) % MOD;
            }
            res.push_back(tmp);
        }
        return res;
    }
};