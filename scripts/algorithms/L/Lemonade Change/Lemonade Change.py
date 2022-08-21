# Runtime: 1581 ms (Top 17.51%) | Memory: 18.1 MB (Top 19.63%)

class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:

        change = {5:0,10:0}
        for i in bills:
            if i==5:
                change[5]+=1
            elif i==10:
                if change[5]>0:
                    change[5]-=1
                    change[10]+=1
                else:
                    return False
            else:
                if (change[10]>0) & (change[5]>0):
                    change[10]-=1
                    change[5]-=1
                elif change[5]>=3:
                    change[5]-=3
                else:
                    return False
        return True