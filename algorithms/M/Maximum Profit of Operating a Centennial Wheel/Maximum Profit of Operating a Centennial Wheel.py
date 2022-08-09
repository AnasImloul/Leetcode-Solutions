import sys
MIN_INT = -sys.maxsize-1
class Solution:
    def minOperationsMaxProfit(self, customers: List[int], boardingCost: int, runningCost: int) -> int:
        maxx = MIN_INT
        rotate = total =  ans = money = num = i = 0
        for i in range(len(customers)):
            total += customers[i]
            rotate = i+1
            if total >= 4:
                num += 4
                total -= 4
            else: 
                num += total
                total = 0
            money = num * boardingCost - rotate * runningCost
            if maxx < money:
                maxx = money
                ans = rotate
        i+=1
        while(total > 0):
            rotate = i+1
            if total >= 4:
                num += 4
                total -= 4
            else: 
                num += total
                total = 0
            money = num * boardingCost - rotate * runningCost
            if maxx < money:
                maxx = money
                ans = rotate
            i+=1
        if maxx < 0: return -1
        return ans
