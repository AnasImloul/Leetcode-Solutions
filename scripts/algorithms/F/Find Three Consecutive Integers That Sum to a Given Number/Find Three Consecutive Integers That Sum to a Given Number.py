// Runtime: 35 ms (Top 76.35%) | Memory: 17.40 MB (Top 18.24%)

class Solution:
    def sumOfThree(self, num: int) -> List[int]:
        temp=(num-3)/3
        if floor(temp)==ceil(temp):
            return [int(temp),int(temp)+1,int(temp)+2]
        else:
            return []
