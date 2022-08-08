class Solution {
    public int kthGrammar(int n, int k) {
       if (n == 1 || k == 1) {
            return 0;
        }
        int length = (int) Math.pow(2, n - 1);
        int mid = length / 2;
        if (k <= mid) {
            return kthGrammar(n - 1, k);
        } else if (k > mid + 1) {
            return invert(kthGrammar(n - 1, k - mid));
        } else {
            return 1;
        }
    }
    static int invert(int x) {
        if (x == 0) {
            return 1;
        }
        return 0;
    }
}
