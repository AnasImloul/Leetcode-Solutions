// Runtime: 248 ms (Top 95.07%) | Memory: 33.70 MB (Top 53.77%)

class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        bool prime[n + 1]; // Array to store whether a number is prime or not
        memset(prime, true, sizeof(prime)); // Initializing all numbers as prime
        prime[1] = false; // 1 is not a prime number
        prime[0] = false; // 0 is not a prime number

        // Finding prime numbers using Sieve of Eratosthenes algorithm
        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                // Marking multiples of p as non-prime
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        vector<vector<int>> ans; // Vector to store the pairs of prime numbers
        for(int i=2;i <= (n-1);i++){
            int j = n - i; // Finding the complement of i to make the sum n
            if(prime[i] && prime[j] && i <= j){
                vector<int> temp = {i,j}; // Creating a pair of prime numbers
                ans.push_back(temp); // Adding the pair to the result vector
            }
        }
        return ans; // Returning the vector of prime pairs
    }
};
