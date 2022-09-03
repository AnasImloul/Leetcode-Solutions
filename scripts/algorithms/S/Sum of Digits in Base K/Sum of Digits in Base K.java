// Runtime: 0 ms (Top 100.00%) | Memory: 41.2 MB (Top 20.16%)
class Solution {
    public int sumBase(int n, int k) {
        int res = 0;
        for (; n > 0; n /= k)
            res += n % k;
        return res;
    }
}