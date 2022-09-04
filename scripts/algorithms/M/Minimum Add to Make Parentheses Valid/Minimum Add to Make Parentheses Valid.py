# Runtime: 53 ms (Top 37.79%) | Memory: 13.8 MB (Top 96.01%)
class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        stack = []

        for parenthese in s:
            if parenthese == "(":
                stack.append("(")

            else:
                if not stack or stack[-1] == ")":
                    stack.append(")")

                if stack and stack[-1] == "(":
                    stack.pop()

        return len(stack)