class Solution {
public:
    int getMaximumGenerated(int n) {
        // base cases
        if (n < 2) return n;
        // support variables
        int arr[n + 1], m;
        arr[0] = 0, arr[1] = 1;
        // building arr
        for (int i = 2; i <= n; i++) {
            if (i % 2) arr[i] = arr[i / 2] + arr[i / 2 + 1];
            else arr[i] = arr[i / 2];
            // updating m
            m = max(arr[i], m);
        }
        return m;
    }
};
