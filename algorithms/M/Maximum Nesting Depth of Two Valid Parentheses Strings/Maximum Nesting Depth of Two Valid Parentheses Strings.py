class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        ans = []
        last = 1
        for i in seq:
            if i == '(':
                if last == 0: ans.append(1)
                else:ans.append(0)
            else:
                ans.append(last)
            last = (last + 1) % 2
        return ans
