# Runtime: 24 ms (Top 18.77%) | Memory: 19.30 MB (Top 44.57%)

class Solution:
    def distinctDifferenceArray(self, nums: List[int]) -> List[int]:
        # One liner
        # return [len(Counter(nums[:i + 1])) - len(Counter(nums[i + 1:])) for i in range(len(nums))]
        prefix = defaultdict(int)
        suffix = Counter(nums)
        result = []
        for x in nums:
            prefix[x] += 1
            suffix[x] -= 1
            if suffix[x] == 0:
                del suffix[x]
            result.append(len(prefix) - len(suffix))
        return result
