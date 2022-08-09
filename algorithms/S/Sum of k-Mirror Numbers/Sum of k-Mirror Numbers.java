class Solution {
    public long kMirror(int k, int n) {
        long res = 0;
        long cnt = 0;
        for (long i = 1; i < Long.MAX_VALUE; i++) {
            if (iskmirror(k,i) && iskmirror(10,i)) {
                res += i;
                cnt++;
                if (cnt == n) {
                    return res;
                }
            }
        }
        return res;
    }
    
    boolean iskmirror(long k, long n) {
        long num = 0;
        long tmp = n;
        while (n != 0) {
            num = num * k + n % k;
            n = n / k;
        }
        return tmp == num;
    }
}
