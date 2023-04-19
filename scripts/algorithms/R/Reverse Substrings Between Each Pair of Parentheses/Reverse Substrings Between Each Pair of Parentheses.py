class Solution:
    def reverseParentheses(self, s: str) -> str:
        stack = []
        ans = ""
        res = deque([])
        s = list(s)
        for i in s:
            if i==")":
                while stack[-1] != "(":
                    res.append(stack.pop())
                stack.pop()
                while res:
                    stack.append(res.popleft())
            else:
                stack.append(i)
        return "".join(stack)