class Solution:
    def compress(self, chars: List[str]) -> int:
        stri = ''
        stack = [chars.pop(0)]
        
        while chars:
            p = chars.pop(0)
            
            if p in stack:
                stack.append(p)
            else:
                stri = stri + stack[-1] + str(len(stack) if len(stack) > 1 else '')
                stack = [p] 
                
        o = list(stri + stack[-1] + str(len(stack) if len(stack) > 1 else ''))
        
        for i in o:
            chars.append(i)
