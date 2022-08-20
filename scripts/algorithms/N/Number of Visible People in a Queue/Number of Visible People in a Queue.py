# Runtime: 2162 ms (Top 20.79%) | Memory: 30.1 MB (Top 6.96%)

class Solution:
    def canSeePersonsCount(self, heights: List[int]) -> List[int]:
        ans=[]
        stack=[]
        n=len(heights)
        for i in range(n-1,-1,-1):
            if len(stack)==0:
                ans.append(0)
                stack.append(heights[i])
            else:
                if heights[i]<stack[-1]:
                    ans.append(1)
                    stack.append(heights[i])
                else:
                    ctr=0
                    while(len(stack)>0 and stack[-1]<heights[i]):
                        ctr+=1
                        stack.pop()
                    if len(stack)==0:
                        ans.append(ctr)
                    else:
                        ans.append(ctr+1)
                    stack.append(heights[i])
        return ans[::-1]