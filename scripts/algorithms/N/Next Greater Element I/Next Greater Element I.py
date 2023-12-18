// Runtime: 50 ms (Top 80.48%) | Memory: 16.70 MB (Top 24.94%)

class Solution:
    def nextGreaterElement(self, nums1, nums2):
        dic, stack = {}, []
        
        for num in nums2[::-1]:
            while stack and num > stack[-1]:
                stack.pop()
            if stack:
                dic[num] = stack[-1]
            stack.append(num)
            
        return [dic.get(num, -1) for num in nums1]
