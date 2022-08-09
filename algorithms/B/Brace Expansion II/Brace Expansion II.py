class Solution:
    def braceExpansionII(self, expression: str) -> List[str]:
        s = list(reversed("{" + expression + "}"))
        
        def full_word(): 
            cur = [] 
            while s and s[-1].isalpha():    
                cur.append(s.pop())            
            return "".join(cur)
        
        def _expr(): 
            res = set()    
            if s[-1].isalpha(): 
                res.add(full_word())    
            elif s[-1] == "{":   
                s.pop() # remove open brace
                res.update(_expr()) 
                while s and s[-1] == ",": 
                    s.pop() # remove comma 
                    res.update(_expr())    
                s.pop() # remove close brace 
            while s and s[-1] not in "},": 
                res = {e + o for o in _expr() for e in res}
            return res    
        
        return sorted(_expr()) 
