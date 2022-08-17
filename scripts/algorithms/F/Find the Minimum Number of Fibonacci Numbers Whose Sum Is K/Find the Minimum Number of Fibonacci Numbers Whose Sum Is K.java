class Solution {
    public int findMinFibonacciNumbers(int k) {
        int ans = 0;

        while (k > 0) {
			// Run until solution is reached
            int fib2prev = 1;
            int fib1prev = 1;
            while (fib1prev <= k) {
				// Generate Fib values, stop when fib1prev is > k, we have the fib number we want stored in fib2prev
                int temp = fib2prev + fib1prev;
                fib2prev = fib1prev;
                fib1prev = temp;
            }
            k -= fib2prev;
            ans += 1;
        }
        return ans;
    }
}
