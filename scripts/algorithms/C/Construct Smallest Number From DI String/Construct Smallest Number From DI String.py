# Runtime: 0 ms (Top 100.00%) | Memory: 19.40 MB (Top 30.58%)

class Solution:
    def smallestNumber(self, pattern: str) -> str:
        ans = [1]
        for ch in pattern: 
            if ch == 'I': 
                m = ans[-1]+1
                while m in ans: m += 1
                ans.append(m)
            else: 
                ans.append(ans[-1])
                for i in range(len(ans)-1, 0, -1): 
                    if ans[i-1] == ans[i]: ans[i-1] += 1
        return ''.join(map(str, ans))
