class Solution {
public:
    bool isHappy(int n) {
        // Create a set...
        set<int> hset;
        while(hset.count(n) == 0) {
            // If total is equal to 1 return true.
            if(n == 1)
                return true;
            // Insert the current number in hset...
            hset.insert(n);
            // Initialize the total...
            int total=0;
            // Create a while loop...
            while(n) {
                // Process to get happy number...
                // We use division and modulus operators to repeatedly take digits off the number until none remain...
                // Then squaring each removed digit and adding them together.
                total += (n % 10) * (n % 10);
                n /= 10;
                // Each new converted number must not had occurred before...
            }
            // Insert the current number into the set s...
            // Replace the current number with total of the square of its digits.
            n = total;
        }
        // If current number is already in the HashSet, that means we're in a cycle and we should return false..
        return false;
    }
};
