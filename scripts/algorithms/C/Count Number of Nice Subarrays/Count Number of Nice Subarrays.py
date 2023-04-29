class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        start = tempodd = count = 0
        first = -1
        for i, num in enumerate(nums):
            # If odd, count the number of odds we got
            # Also lets keep track of first odd we encounter
            if num % 2:
                tempodd += 1
                if first == -1:
                    first = i
            # If we get k odds or more, we should count the subarrays
            if tempodd >= k:
                # We got one more than k counts, Just remove the first odd
                if tempodd > k:
                    first = start = first + 1
                    while nums[first] % 2 == 0:
                        first = first + 1
                    tempodd -= 1
                # If we get exact k odds, we should count the subarrays
                count += first - start + 1
        return count