// Runtime: 98 ms (Top 86.97%) | Memory: 89.70 MB (Top 86.09%)

#include <vector>
#include <algorithm>

class Solution {
public:
    int paintWalls(std::vector<int>& cost, std::vector<int>& time) {
        int n = cost.size(); // Get the number of walls
        std::vector<int> dp(n + 1, 1e9); // Create a dynamic programming array to store the minimum cost
        dp[0] = 0; // The minimum cost to paint 0 walls is 0 (base case)

        // Loop through each wall
        for (int i = 0; i < n; ++i) {
            // Loop through the dynamic programming array in reverse order
            for (int j = n; j > 0; --j) {
                // Calculate the minimum cost to paint 'j' walls using the current wall 'i'
                // The minimum cost at 'j' is the minimum of:
                //   - The cost of painting the current wall 'i' + the cost of painting the previous walls (dp[j - time[i] - 1])
                //   - The cost of painting the previous walls without using the current wall 'i' (dp[j])
                dp[j] = std::min(dp[j], dp[std::max(j - time[i] - 1, 0)] + cost[i]);
            }
        }
        return dp[n]; // The minimum cost to paint all 'n' walls is stored in dp[n]
    }
};
