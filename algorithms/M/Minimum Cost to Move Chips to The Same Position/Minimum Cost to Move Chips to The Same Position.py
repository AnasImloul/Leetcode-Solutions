class Solution:
    def minCostToMoveChips(self, position: List[int]) -> int:
        count_even=0
        count_odd=0
        for i in position:
            if i%2==0:
                count_even+=1
            else:
                count_odd+=1
        return min(count_even,count_odd)
