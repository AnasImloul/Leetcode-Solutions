import heapq

class Solution:
    def findRoot(self, roots, idx):
        if roots[idx] == idx:
            return idx
        roots[idx] = self.findRoot(roots, roots[idx])
        return roots[idx]
    
    def merge(self, roots, left, right):
        roots[self.findRoot(roots, left)] = self.findRoot(roots, right)

    def minimizeMax(self, nums: List[int], p: int) -> int:
        nums = sorted(nums)
        heap = []
        for i in range(1, len(nums)):
            heapq.heappush(heap, (nums[i] - nums[i - 1], i - 1, i))
        minMaxDiff = 0
        odd = [True for _ in range(len(nums))]
        roots = [i for i in range(len(nums))]
        while p > 0:
            diff, left, right = heapq.heappop(heap)
            rootLeft = self.findRoot(roots, left)
            rootRight = self.findRoot(roots, right)
            self.merge(roots, left, right)
            if odd[rootLeft] and odd[rootRight]:
                p -= 1
                minMaxDiff = diff
                odd[self.findRoot(roots, left)] = False
            elif odd[rootLeft] or odd[rootRight]:
                odd[self.findRoot(roots, left)] = True
            
        return minMaxDiff
