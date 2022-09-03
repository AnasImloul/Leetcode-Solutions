// Runtime: 178 ms (Top 61.28%) | Memory: 109.5 MB (Top 34.27%)
class Solution {
    public int totalStrength(int[] strength) {
        int mod = 1000000007;

        int len = strength.length;

        long[] prefix = prefixSum(strength, len, mod);

        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(-1);

        long ans = 0;
        for(int i = 0; i < len; i++) {
            while(stack.peek() != -1 && strength[i] <= strength[stack.peek()]) {
                int mid = stack.pop();
                int left = stack.peek() + 1;
                int right = i - 1;

                int n = (mid - left);
                int t = (right - mid);

                long val = (1l * (1 + n) * (prefix[right + 2] - prefix[mid + 1]) + mod) % mod;
                val -= (1l * (1 + t) * (prefix[mid + 1] - prefix[left]) + mod) % mod;
                val *= strength[mid];

                ans += val;
                ans %= mod;
            }

            stack.push(i);
        }

        int right = len - 1;
        while(stack.peek() != -1) {
            int mid = stack.pop();
            int left = stack.peek() + 1;

            int n = (mid - left);
            int t = (right - mid);

            long val = (1l * (1 + n) * (prefix[right + 2] - prefix[mid + 1]) + mod) % mod;
            val -= (1l * (1 + t) * (prefix[mid + 1] - prefix[left]) + mod) % mod;
            val *= strength[mid];

            ans += val;
            ans %= mod;
        }

        return (int)((ans + mod) % mod);
    }

    private long[] prefixSum(int[] strength, int len, int mod) {
        long[] prefix = new long[len + 1];

        for(int i = 0; i < len; i++) {
            prefix[i + 1] = prefix[i] + strength[i];
        }

        long[] doublePrefix = new long[len + 2];
        for(int i = 0; i <= len; i++) {
            doublePrefix[i + 1] = (doublePrefix[i] + prefix[i]) % mod;
        }

        return doublePrefix;
    }
}