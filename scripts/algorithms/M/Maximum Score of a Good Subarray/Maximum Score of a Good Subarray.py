class Solution:
    def nextSmallerElement(self, nums):
        nextSmaller = [None] * len(nums)
        stack = [[-sys.maxsize, -1]]
        for i in range(len(nums)-1, -1, -1):
            while nums[i] <= stack[-1][0]:
                stack.pop()
            nextSmaller[i] = stack[-1][1]
            stack.append([nums[i], i])
        return nextSmaller
            
    
    def previousSmallerElement(self, nums):
        previousSmaller = [None] * len(nums)
        stack = [[-sys.maxsize, -1]]
        for i in range(len(nums)):
            while nums[i] <= stack[-1][0]:
                stack.pop()
            previousSmaller[i] = stack[-1][1]
            stack.append([nums[i], i])
        return previousSmaller
    
    def maximumScore(self, nums: List[int], k: int) -> int:
        nextSmaller = self.nextSmallerElement(nums)
        previousSmaller = self.previousSmallerElement(nums)

        score = 0
        for idx, num in enumerate(nums):
			# previousSmaller[idx] (let's say i) and nextSmaller[idx] (let's say j) ensures that the element present at idx is the minimum in range (i -> j)
            i = previousSmaller[idx]
            i += 1
            j = nextSmaller[idx]
            if j == -1:
                j = len(nums)
            j -= 1
            if i <= k <= j:
                score = max(score, num * (j-i+1))
        
        return score
            
