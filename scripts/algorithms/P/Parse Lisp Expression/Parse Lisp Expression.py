class Solution:
    def evaluate(self, expression: str) -> int:
        loc = {}
        stack = []
        for i, x in enumerate(expression): 
            if x == "(": stack.append(i)
            elif x == ")": loc[stack.pop()] = i
        
        def fn(lo, hi, mp): 
            """Return value of given expression."""
            if expression[lo] == "(": return fn(lo+1, hi-1, mp)
            i = lo
            vals = []
            while i < hi: 
                if expression[i:i+3] in ("let", "add"): 
                    op = expression[i:i+3]
                    i += 3
                elif expression[i:i+4] == "mult": 
                    op = "mult"
                    i += 4
                elif expression[i].isalpha(): 
                    x = ""
                    while i < hi and expression[i].isalnum(): 
                        x += expression[i]
                        i += 1
                    if op in ("add", "mult"): vals.append(mp[x])
                elif expression[i].isdigit() or expression[i] == "-": 
                    v = ""
                    while i < hi and (expression[i].isdigit() or expression[i] == "-"): 
                        v += expression[i]
                        i += 1
                    if op == "let": mp[x] = int(v)
                    else: vals.append(int(v))
                elif expression[i] == "(": 
                    v = fn(i+1, loc[i], mp.copy())
                    i = loc[i] + 1
                    if op == "let": mp[x] = v
                    else: vals.append(v)
                else: i += 1
            if op == "let": return int(v)
            elif op == "add": return sum(vals)
            else: return reduce(mul, vals)
            
        return fn(0, len(expression), {})