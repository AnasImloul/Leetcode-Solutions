**class Solution:
    def largestRectangleArea(self, h: List[int]) -> int:
        stack,n=[],len(h)
        left,right=[0]*n,[0]*n
        
        for i in range(n):
            if len(stack)==0:
                left[i]=0
            else:
                while(len(stack)!=0 and h[stack[-1]]>=h[i]):
                    stack.pop()
                if len(stack)==0:
                    left[i]=0
                else:
                    left[i]=stack[-1]+1
            stack.append(i)
            
        while(stack):
            stack.pop()
            
        for i in range(n-1,-1,-1):
            if len(stack)==0:
                right[i]=n-1
            else:
                while(len(stack)!=0 and h[stack[-1]]>=h[i]):
                    stack.pop()
                if len(stack)==0:
                    right[i]=n-1
                else:
                    right[i]=stack[-1]-1
            stack.append(i)
            
        print(left)
        print(right)
        
        area=0
        for i in range(n):
            area=max(area,h[i]*(right[i]-left[i]+1))
        return area**
