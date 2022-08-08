class SegmentTreeNode:
    def __init__(self, low, high):
        self.low = low
        self.high = high
        self.left = None
        self.right = None
        self.max = 0

class Solution:       
    def _build(self, left, right):
        root = SegmentTreeNode(self.coords[left], self.coords[right])
        if left == right:
            return root
        
        mid = (left+right)//2
        root.left = self._build(left, mid)
        root.right = self._build(mid+1, right)
        return root
    
    def _update(self, root, lower, upper, val):
        if not root:
            return
        if lower <= root.high and root.low <= upper:# intersect
            root.max = val
            self._update(root.left, lower, upper, val)
            self._update(root.right, lower, upper, val)
        
    def _query(self, root, lower, upper):
        if lower <= root.low and root.high <= upper:
            return root.max
        if upper < root.low or root.high < lower:
            return 0
        return max(self._query(root.left, lower, upper), self._query(root.right, lower, upper))
    
    def fallingSquares(self, positions: List[List[int]]) -> List[int]:
		# coordinates compression
        coords = set()
        for left, size in positions:
            right = left+size-1
            coords.add(left)
            coords.add(right)
        self.coords = sorted(list(coords))
        root = self._build(0, len(self.coords)-1)
        
        res = []
        for left, size in positions:
            right = left+size-1
            h = self._query(root, left, right) + size
            res.append(max(res[-1],h)) if res else res.append(h)
            self._update(root, left, right, h)
        return res
