class Solution {
    public int numTrees(int n) {
        // Create 'sol' array of length n+1...
        int[] sol = new int[n+1];
        // The value of the first index will be 1.
        sol[0] = 1;
        // Run a loop from 1 to n+1...
        for(int i = 1; i <= n; i++) {
            // Within the above loop, run a nested loop from 0 to i...
            for(int j = 0; j < i; j++) {
                // Update the i-th position of the array by adding the multiplication of the respective index...
                sol[i] += sol[j] * sol[i-j-1];
            }
        }
        // Return the value of the nth index of the array to get the solution...
        return sol[n];
    }
}
