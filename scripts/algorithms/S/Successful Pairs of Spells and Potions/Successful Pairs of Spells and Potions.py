# Runtime: 3070 ms (Top 29.46%) | Memory: 37.4 MB (Top 40.00%)
class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        result = self.function(spells,potions,success)
        return result

    def function(self,arr1,arr2,success):
        n2 = len(arr2)
        arr2.sort() #Sorting Enables Us To Do Binary Search
        ans = []
        for i in arr1:
            val = math.ceil(success/i) #Finding the Value Of Portion With Least Strength So That It Can Be Greater Than Success
            idx = bisect.bisect_left(arr2,val) #Finding The Left Most Index So That The Value Can Be Inserted
            res = n2-idx+1 #Calculating the remaining numbers after finding the suitable index
            ans.append(res-1)
        return ans