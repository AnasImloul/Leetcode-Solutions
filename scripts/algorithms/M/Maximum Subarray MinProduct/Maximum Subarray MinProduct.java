// Runtime: 11 ms (Top 95.5%) | Memory: 61.07 MB (Top 6.4%)

class Solution {
    public int maxSumMinProduct(int[] a) {
        int n = a.length, M = 1_000_000_007;
        long res = 0L;

        //step 1; get prefixs um
        long [] psum = new long[n + 1];
        for(int i = 0; i < n; i++) psum[i+1] = psum[i] + a[i];

        //step 2: get the left and right bound of each sub-array using mono deceasing & increasing stack
        int[] s = new int[n];
        int top = -1; // mono-decreasing for right bound
        for (int i = 0; i <= n; s[++top] = i++)
            while (top >= 0 && (i == n || a[i] < a[s[top]])) {
                int min = a[s[top--]]; // get curMin value and poll current index out of stack, it's left and right bouldary is not determined
                int l = top == -1 ? 0 : s[top] + 1; // use the prev idx to get left bound, inclusive
                int r = i - 1; // right bound, inclusive
                res = Math.max(res, min * (psum[r+1] - psum[l]));
            }

        return (int) (res % M);
    }
}