// Runtime: 289 ms (Top 50.82%) | Memory: 17.8 MB (Top 60.66%)
class Solution {
public:
    vector<int>D;
    long long s, last;
    long long memo[1010][1010];
    long long dfs_with_minimum_time_with_k_skip(int idx, int k) {
        if (idx < 0 ) return 0;
        long long &ret = memo[idx][k];
        if (ret != -1 ) return ret;
        long long d = dfs_with_minimum_time_with_k_skip(idx - 1, k) + D[idx];
        if (d % s) d = ((d/s) + 1)*s;
        ret = d;
        if (k > 0 ) ret = min(ret, dfs_with_minimum_time_with_k_skip(idx - 1, k - 1) + D[idx]);
        return ret;
    }
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n = dist.size();
        D = dist, s = speed;
        int lo = 0, hi = n;
        long long d = 0, H = hoursBefore;
        H *=s;
        last = dist[n-1];
        for (int dd : dist) d += dd;
        memset(memo, -1, sizeof(memo));
        if (d /s > hoursBefore) return -1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            long long h = dfs_with_minimum_time_with_k_skip(n-2, mid) + last; // we should start from second last since it is not required to rest on last road
            if (h <= H ) hi = mid;
            else lo = mid + 1;
        }
        return lo == D.size() ? -1 : lo;

    }
};