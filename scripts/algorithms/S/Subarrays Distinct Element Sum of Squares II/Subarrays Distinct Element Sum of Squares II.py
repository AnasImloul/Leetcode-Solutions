# Runtime: 4561 ms (Top 34.62%) | Memory: 70.20 MB (Top 43.69%)

MOD = 1_000_000_007


class SegmentTreeNode:
    def __init__(self, lo, hi) -> None:
        self.lo = lo
        self.hi = hi
        self.val = 0
        self.lazy = 0
        if lo + 1 < hi:
            mid = (lo + hi) // 2
            self.left = SegmentTreeNode(lo, mid)
            self.right = SegmentTreeNode(mid, hi)

    def update(self, val):
        self.lazy += val
        self.val += val * (self.hi - self.lo)

    def query(self, lo, hi):
        if self.lo >= lo and self.hi <= hi:
            res = self.val
            self.update(1)
            return res
        mid = (self.lo + self.hi) // 2
        res = 0
        self.left.update(self.lazy)
        self.right.update(self.lazy)
        self.lazy = 0
        if lo < mid:
            res += self.left.query(lo, hi)
        if hi > mid:
            res += self.right.query(lo, hi)
        self.val = self.left.val + self.right.val
        return res


class Solution:
    def sumCounts(self, nums: list[int]) -> int:
        last_idx_dict = {}
        segment_tree = SegmentTreeNode(0, len(nums))
        res = 0
        curr_res = 0
        for i, num in enumerate(nums):
            last_idx = last_idx_dict.get(num, -1) + 1
            curr_res = (
                curr_res + i - last_idx + 1 + 2 * segment_tree.query(last_idx, i + 1)
            ) % MOD
            res += curr_res
            last_idx_dict[num] = i
        return res % MOD
