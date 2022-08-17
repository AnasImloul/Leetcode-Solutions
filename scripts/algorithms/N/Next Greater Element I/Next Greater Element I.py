
class Solution(object):
    def nextGreaterElement(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
      """
        
        
        
      # index of the next greater for nums2
        
        stack = []
        nextGreater = [-1]*len(nums2)
    
        for i in range(len(nums2)):

            while (stack and nums2[stack[-1]] < nums2[i]):
                nextGreater[stack.pop()] = i
        
            stack.append(i)
      
        
        
        
        # map nums to its idx so we can map from nums1 to nums2 quickly
        mapIdx2 = {}
        for i,num in enumerate(nums2):
            mapIdx2[num] = i
        
        
    
        ans = []
        for num in nums1:
            idx = nextGreater[mapIdx2[num]]
            ans.append( nums2[idx] if idx != -1 else idx)
        return ans
            
    

