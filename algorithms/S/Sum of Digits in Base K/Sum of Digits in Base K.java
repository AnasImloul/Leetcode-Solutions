class Solution {
    public int sumBase(int n, int k) {
        int res = 0;
        for (; n > 0; n /= k)
            res += n % k;
        return res;
    }
}
