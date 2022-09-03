// Runtime: 3 ms (Top 47.06%) | Memory: 41.5 MB (Top 32.65%)
class Solution {
    public boolean isHappy(int n) {
        // Create a hash set...
        Set<Integer> hset = new HashSet<Integer>();
        // If the number is not in the HashSet, we should add it...
        while (hset.add(n)) {
            // Initialize the total...
            int total = 0;
            // Create a while loop...
            while (n > 0) {
                // Process to get happy number...
                // We use division and modulus operators to repeatedly take digits off the number until none remain...
                // Then squaring each removed digit and adding them together...
                total += (n % 10) * (n % 10);
                n /= 10;
                // Each new converted number must not had occurred before...
            }
            // If total is equal to 1 return true.
            if (total == 1)
                return true;
            // Insert the current number into the set s...
            // Replace the current number with total of the square of its digits.
            else
                n = total;
        }
        // If current number is already in the HashSet, that means we're in a cycle and we should return false..
        return false;
    }
}