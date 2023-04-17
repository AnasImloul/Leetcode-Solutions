class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        ans=0
        fruitdict=defaultdict()
        stack=[]
        i,j=0,0

        while j<len(fruits):
            if fruits[j] not in fruitdict and len(fruitdict)<2:
                stack.append(fruits[j])
                fruitdict[fruits[j]]=j
                j+=1

            elif  fruits[j] in fruitdict:
                fruitdict[fruits[j]]=j
                j+=1

            else:  
                if fruitdict[stack[0]]>fruitdict[stack[1]]  :
                    i = fruitdict[stack[1]]+1
                    del fruitdict[stack[1]]
                    stack.pop()
                else:
                    i = fruitdict[stack[0]]+1
                    del fruitdict[stack[0]] 
                    stack.pop(0)              
            
            ans=max(ans,j-i)
        return ans