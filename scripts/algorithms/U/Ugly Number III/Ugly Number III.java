// Runtime: 0 ms (Top 100.0%) | Memory: 40.60 MB (Top 12.2%)

class Solution {
    public int nthUglyNumber(int n, int a, int b, int c) {
        int left = 1;
        int right = Integer.MAX_VALUE;
        int count = 0;
        while (left < right) {
            int middle = left + (right - left) / 2;
            if (isUgly(middle, a, b, c, n)) {
                right = middle;
            }
            else
                left = middle + 1;
        }
        return left;
    }
    public boolean isUgly(long middle, long a, long b, long c, long n) {
        return (int) (middle/a + middle/b + middle/c - middle/lcm(a, b) - middle/lcm(b, c) - middle/lcm(c, a) + middle/lcm(a, lcm(b, c))) >= n;
    }
    public long gcd(long a, long b) {
        if (a == 0)
            return b;
        else return gcd(b%a, a);
    }
    public long lcm(long a, long b) {
        return a * b / (gcd(a, b)); 
    }
}
