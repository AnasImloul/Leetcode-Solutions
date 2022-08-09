from sortedcontainers import SortedList
class Solution:
    """
    For each sub array nums[0, i]
    We sum the reverse pairs count
    of x, s.t x in [0, i-1] and nums[x] >= 2 * nums[i] + 1 
    Using a BST(sortedList) to get logN insert and lookup time.
    Time: O(NlogN)
    Space: O(N)
    """
    def reversePairs(self, nums: List[int]) -> int:
        res = 0
        bst = SortedList()
        for e in nums:
            res += len(bst) - bst.bisect_left(2 * e + 1) # the count is the N - index
            bst.add(e) # add the the bst
        return res
