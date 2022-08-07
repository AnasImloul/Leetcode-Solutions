class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []      
        for i in tokens:
            if i == "+":
                stack[-1] = stack[-2] + stack.pop()
            elif i == "-":
                stack[-1] = stack[-2] - stack.pop()
            elif i == "*":
                stack[-1] = stack[-2] * stack.pop()
            elif i == "/":
                stack[-1] = int(stack[-2] / stack.pop())
            else:
                stack.append(int(i))
                
        return stack.pop()
                    
