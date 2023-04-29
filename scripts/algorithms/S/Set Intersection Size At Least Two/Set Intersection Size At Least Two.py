class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        ans = []
        for x, y in sorted(intervals, key=lambda x: (x[1], -x[0])): 
            if not ans or ans[-2] < x: 
                if ans and x <= ans[-1]: ans.append(y)
                else: ans.extend([y-1, y])
        return len(ans)