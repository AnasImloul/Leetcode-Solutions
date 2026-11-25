# Runtime: 2042 ms (Top 13.95%) | Memory: 45.90 MB (Top 41.86%)

from sortedcontainers import SortedSet

class Solution:
    def maxBalancedSubsequenceSum(self, nums: List[int]) -> int:

        treeSet = SortedSet()
        # map: nums[i]-i -> max_total
        valMap = {}
        res = -inf

        for i, num in enumerate(nums):
            x = num-i

            total = num
            pos = treeSet.bisect_right(x)-1
            if pos >= 0:
                val2 = valMap[treeSet[pos]]

                total = max(num, num + val2, val2)

            # remove anything on the right side of the element in the tree that has a lower max_total value. 
            while pos+1 < len(treeSet) and valMap[treeSet[pos+1]] < total:
                del treeSet[pos+1]

            treeSet.add(x)
            valMap[x] = max(total, valMap.get(x, -inf))
            res = max(res, total)

        return res
