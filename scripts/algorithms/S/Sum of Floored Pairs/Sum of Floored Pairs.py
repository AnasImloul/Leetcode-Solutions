class Solution:
    def sumOfFlooredPairs(self, nums: List[int]) -> int:
        
        incs, counter=[0]*(max(nums)+1), Counter(nums)            # To store all the quotients increases; counter
        for num in counter:                                       # Loop over all the divisors
            for j in range(num, len(incs), num):                  # Loop over all the possible dividends where the quotient increases
                incs[j] += counter[num]                           # Increment the increases in quotients
        quots=list(accumulate(incs))                              # Accumulate the increases to get the sum of quotients
        return sum([quots[num] for num in nums]) % 1_000_000_007  # Sum up all the quotients for all the numbers in the list.
