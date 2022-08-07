class Solution:
    def isValid(self, code: str) -> bool:
        if code[0] != '<' or code[-1] != '>': return False
        i, n = 0, len(code)
        stk = []
        while i < n:
            if code[i] == '<':
                if i != 0 and code[i: i + 9] == '<![CDATA[':
                    if not stk: return False
                    j = i + 9
                    while j + 3 <= n and code[j: j + 3] != ']]>': j += 1
                    if code[j: j + 3] == ']]>': i = j + 3
                    else: return False
                else:
                    start = i
                    isend = False
                    i += 1
                    if i >= n: return False
                    if code[i] == r'/':
                        isend = True
                        i += 1
                    if i >= n: return False
                    tag = ''
                    while i < n and code[i] != '>':
                        if not code[i].isupper(): return False
                        tag += code[i]
                        i += 1
                    if i >= n or len(tag) == 0 or len(tag) > 9: return False
                    if isend:
                        if not stk or stk[-1] != tag: return False
                        stk.pop(-1)
                    else:
                        if start != 0 and not stk: return False
                        stk.append(tag)
                    i += 1
            else:
                if not stk: return False
                while i < n and code[i] != '<': i += 1
        return not stk
