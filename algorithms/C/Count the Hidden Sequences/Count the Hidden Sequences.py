class Solution:
    def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
        l = [0]
        for i in differences:
            l.append(l[-1]+i)
        return max(0,(upper-lower+1)-(max(l)-min(l)))
