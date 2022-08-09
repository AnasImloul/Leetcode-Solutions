class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
		counter = collections.Counter(arr)
        available = sum(n > len(arr) for n in arr)
        i = ans = len(arr)
        while i > 0:
            # This number is not in arr
            if not counter[i]:
                # Use another number to fill in its place. If we cannot, we have to decrease our max
                if available: available -= 1               
                else: ans -= 1
            # Other occurences can be used for future.
            else:
                available += counter[i] - 1
            i -= 1
        return ans
