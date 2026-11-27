# Runtime: 24 ms (Top 9.79%) | Memory: 19.00 MB (Top 82.92%)

class Solution:
    # Function to count the number of tested devices
    def countTestedDevices(self, bp):
        n = len(bp)  # Size of the battery percentage array
        cnt = 0  # Counter for tested devices

        for i in range(n):
            if bp[i] > 0:
                cnt += 1  # Increment tested devices count
                for j in range(i + 1, n):
                    # Decrement battery percentage by 1, ensuring it doesn't go below 0
                    bp[j] = max(0, bp[j] - 1)

        return cnt  # Return the count of tested devices
