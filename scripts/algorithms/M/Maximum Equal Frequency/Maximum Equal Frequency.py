class Solution:
    def maxEqualFreq(self, nums: List[int]) -> int:
        ans = 0
        n = len(nums)
        countToFreq = defaultdict(int)
        # key = count value = Freq ex 2 occured 3 times  in nums so 2 : 3
        freqToCount = defaultdict(int)
        # key = freq value = count ex 2 numbers occured 3 times in nums so 2 : 3
        
        for i,val in enumerate(nums):
            
            x = countToFreq[val] + 1
            freqToCount[x - 1] -= 1
            if freqToCount[x - 1] <= 0 : freqToCount.pop(x - 1)
            freqToCount[x] += 1
            countToFreq[val] = x
            
            # if a single item is repeated for i + 1 times like [1,1,1]
            if countToFreq[val] == i + 1 :ans = i + 1
            
            # if all items are having same frequency like [2,2,1,1,3,3]
            elif (i < n-1 and len(freqToCount) == 1) or (len(freqToCount) == 1 and max(freqToCount.keys())==1): ans = i + 1
            
            # if all items have same frequency except one having 1 freq like [2,2,3,3,1]
            elif len(freqToCount) == 2 and 1 in freqToCount and freqToCount[1] == 1:ans = i +1
            
            # if all items have same frequenct except one having freq common + 1 like[1,1,2,2,3,3,3]
            elif len(freqToCount) == 2:
                keys,values = [],[]
                for j in freqToCount:keys.append(j) , values.append(freqToCount[j])
                if (keys[0]==1+keys[1] and values[0]==1) or (keys[1]==1+keys[0] and values[1]==1):ans = i + 1
        return ans
