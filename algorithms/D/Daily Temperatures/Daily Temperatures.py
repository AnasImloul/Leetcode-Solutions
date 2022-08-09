class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        # Next greater number
        res = [0] * len(temperatures)
		# store the index
        stack = []
        for i, temp in enumerate(temperatures):
            while stack and temperatures[stack[-1]] < temp:
                res[stack[-1]] = i - stack[-1]
                stack.pop()
            
            stack.append(i)
        return res
