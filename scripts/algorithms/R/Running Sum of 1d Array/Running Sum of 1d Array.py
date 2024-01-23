// Runtime: 39 ms (Top 85.2%) | Memory: 16.70 MB (Top 56.78%)

class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        # The variable that will have the running sum
        tot = 0
        # The array that will hold the running su,
        ans = []
        # For loop
        for ele in nums:
            # Adding the element
            tot += ele
            # Appending this running sum to ans
            ans.append(tot)
        # Return ans
        return ans
