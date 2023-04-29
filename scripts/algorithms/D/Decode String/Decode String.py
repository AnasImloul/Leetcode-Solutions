class Solution:
    def decodeString(self, s: str) -> str:
        stk = []
        
        for i in range(len(s)):
            
            if s[i] != ']':
                stk.append(s[i])  
            else:
                strr = ''
                while stk[-1] != '[':
                    strr = stk.pop() + strr
                stk.pop()
                
                num = ''
                while stk and stk[-1].isdigit():
                    num = stk.pop() + num
                    
                stk.append(int(num) * strr)
        
        return ''.join(stk)
                    
                    
                    