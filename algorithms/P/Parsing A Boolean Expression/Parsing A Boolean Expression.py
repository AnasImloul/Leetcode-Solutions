class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        
        # expresssion map
        opMap = {"!" : "!", "|" : "|" , "&" : "&"}
        expMap = {"t" : True, "f" : False}
        expStack = []
        opStack = []
        ans = 0
        i = 0
        
        while i < len(expression):
            
            if expression[i] in opMap:
                opStack.append(opMap[expression[i]])
            
            elif expression[i] in expMap:
                expStack.append(expMap[expression[i]])
                
            elif expression[i] == "(":
                expStack.append("(")
            
            # strat performing operations
            elif expression[i] == ")":
                op = opStack.pop()
                ans = [] # evaluator arr
                
                # To Check
                # print("EXPSTACK :- ", expStack, "OPSTACK :- ", opStack, "outer WHILE")
                
                # Performing serries of operation on exp inside a ()
                while expStack[-1] != "(":
                    
                    # To check 
                    # print("EXPSTACK :- ", expStack, "OPSTACK :- ", opStack, "OPerator :- ",op, "INNER WHILE")
    
                    # Not single operation only
                    if op == "!":
                        ans.append(not expStack.pop())
                    else:
                        ans.append(expStack.pop())
                
                # Operation evaluation for more then 1 exp inside () for &, or
                while len(ans) > 1:
                    # or
                    if op == "|":
                        exp1, exp2 = ans.pop(), ans.pop()
                        res = exp1 or exp2
                        ans.append(res)
                    # and
                    elif op == "&":
                        exp1, exp2 = ans.pop(), ans.pop()
                        res = exp1 and exp2
                        ans.append(res)
                    
                # poping ")" and adding the res of operation done above
                expStack.pop() # poping ")"
                expStack.append(ans[-1])
                        
            # increment i   
            i += 1
                
        return expStack[-1]
    
    
"""
TC : O(n * m) | n = len(expression), m = no of expression inside a prenthesis
Sc : O(n)
"""
