class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        t=len(nums)
        nums+=nums
        l=[-1]*len(nums)
        d={}
        stack=[0]
        for x in range(1,len(nums)):
            #print(x)
            if nums[x]>nums[stack[-1]]:
                while nums[x]>nums[stack[-1]] :
                    l[stack[-1]]=nums[x]
                    stack.pop()
                    if stack==[]:
                        break
                    #print(l)
                stack.append(x)
                    
            else:
                stack.append(x)
        return l[:t]
            
        
