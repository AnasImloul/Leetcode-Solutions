# Runtime: 1 ms (Top 88.33%) | Memory: 19.20 MB (Top 43.75%)

class Solution:
    def findMinimumOperations(self, s1: str, s2: str, s3: str) -> int:
        len_str = min(len(s1), len(s2), len(s3)) # Calculate the length of the shortest string among s1, s2, and s3
        sum_len = len(s1) + len(s2) + len(s3) # Sum of lengths of all three strings

        # Check if the first characters of s1, s2, and s3 are not the same
        if s1[0] != s2[0] or s1[0] != s3[0] or s2[0] != s3[0]:
            return -1 # If not the same, return -1 as it's impossible to match the first character

        # Iterate through the strings until a mismatch is found
        for i in range(len_str):
            if s1[i] == s2[i] == s3[i]:
                sum_len -= 3 # Decrement the sum by 3 for each matching character in the strings
            else:
                break # Break the loop when a mismatch is encountered

        return sum_len # Return the sum of lengths of three strings minus the matched characters
