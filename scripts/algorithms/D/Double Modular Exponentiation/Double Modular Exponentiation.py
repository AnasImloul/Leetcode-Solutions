# Runtime: 17 ms (Top 6.54%) | Memory: 19.20 MB (Top 81.31%)

class Solution:
    def getGoodIndices(self, variables, target):
        ans = [] # Resultant list to store good indices
        k = 0 # Counter for keeping track of the index

        for x in variables: # Loop through the 'variables' list
            m, b, c, d = x # Extract values from subarray

            n1 = 1 # Initialize n1

            # Calculate (m ^ b) % 10
            for i in range(b):
                n1 = (n1 * m) % 10

            n2 = 1 # Initialize n2

            # Calculate (n1 ^ c) % d
            for i in range(c):
                n2 = (n2 * n1) % d

            # Check if n2 matches the target
            if n2 == target:
                ans.append(k) # If true, add index 'k' to the answer list

            k += 1 # Increment the index counter

        return ans # Return the resulting list containing good indices
