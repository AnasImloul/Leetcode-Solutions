// Runtime: 12 ms (Top 98.51%) | Memory: 8.60 MB (Top 86.57%)

vector<int> p{2};
bool sieve[1000001] = {};
class Solution {
public:
vector<int> closestPrimes(int left, int right) {
    if (p.size() == 1)
        for (long long i = 3; i < 1000001; i += 2)
            if (!sieve[i]) {
                p.push_back(i);
                for (long long d = i * i; d < 1000001; d += i)
                    sieve[d] = true;
            }
    int n1 = -1, n2 = -1, i = lower_bound(begin(p), end(p), left) - begin(p);
    for (; i + 1 < p.size() && p[i + 1] <= right; ++i)
        if (n1 == -1 || p[i + 1] - p[i] < n2 - n1) {
            n1 = p[i];
            n2 = p[i + 1];
            if (n2 - n1 < 3)
                break;
        }
    return {n1, n2};
}
};
