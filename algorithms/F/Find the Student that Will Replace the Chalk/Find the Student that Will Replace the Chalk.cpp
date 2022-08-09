class Solution {
public:
    // T(n) = O(n) S(n) = O(1) 
    int chalkReplacer(vector<int>& chalk, int k) {
        // Size of the vector
        int n = chalk.size();
        // Store the sum of the elements in the vector
        long sum = 0;
        // Calculate the sum of the elements 
        for (int n : chalk) sum += n;
        // Update k as the remainder of the sum 
        // to make sure that the while loop
		// will traverse the vector at most 1 time
        k = k % sum;
        // Start from the initial value in the array
        int idx = 0;
        // While the next student has enough chalk
        while (k >= chalk[idx]) {
            // Decrease the remaining chalk
            k -= chalk[idx];
            // Increase the index
            idx = (idx + 1) % n;
        }
        // Return the index of the student without
        // enough chalk
        return idx;
    }
};
