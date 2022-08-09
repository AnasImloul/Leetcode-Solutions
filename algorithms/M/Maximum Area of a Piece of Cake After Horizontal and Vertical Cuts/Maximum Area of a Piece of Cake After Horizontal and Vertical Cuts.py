class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        horizontalCuts.sort()
        verticalCuts.sort()
        
        mxHr = 0
        prev = 0
        for i in horizontalCuts:
            mxHr = max(mxHr, i-prev)
            prev = i
        mxHr = max(mxHr, h-horizontalCuts[-1])
        
        mxVr = 0
        prev = 0
        for i in verticalCuts:
            mxVr = max(mxVr, i-prev)
            prev = i
        mxVr = max(mxVr, w-verticalCuts[-1])
        
        return (mxHr * mxVr) % ((10 ** 9) + 7)
