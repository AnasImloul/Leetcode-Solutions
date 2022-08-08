class Solution {
    public int preimageSizeFZF(int k) {
        long n = 4L * k;
        int resp = 0;
        while (true) {
            int t = zeros(n);
            if (t > k) return 0;
            if (t == k) return 5;
            n++;
        }
    
    }
    
    private int zeros(long n) {
        int resp = 0;
        while (n > 0) {
            resp += (int)(n / 5);
            n /= 5;
        }
        return resp;
    }
}
