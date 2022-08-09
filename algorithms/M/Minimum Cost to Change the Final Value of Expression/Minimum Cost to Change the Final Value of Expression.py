class Solution:
    def minOperationsToFlip(self, expression: str) -> int:
        loc = {}
        stack = []
        for i in reversed(range(len(expression))):
            if expression[i] == ")": stack.append(i)
            elif expression[i] == "(": loc[stack.pop()] = i 
        
        def fn(lo, hi): 
            """Return value and min op to change value."""
            if lo == hi: return int(expression[lo]), 1
            if expression[hi] == ")" and loc[hi] == lo: return fn(lo+1, hi-1) # strip parenthesis 
            mid = loc.get(hi, hi) - 1 
            v, c = fn(mid+1, hi)
            vv, cc = fn(lo, mid-1)
            if expression[mid] == "|": 
                val = v | vv 
                if v == vv == 0: chg = min(c, cc)
                elif v == vv == 1: chg = 1 + min(c, cc)
                else: chg = 1 
            else: # expression[k] == "&"
                val = v & vv
                if v == vv == 0: chg = 1 + min(c, cc)
                elif v == vv == 1: chg = min(c, cc)
                else: chg = 1
            return val, chg
                    
        return fn(0, len(expression)-1)[1]
