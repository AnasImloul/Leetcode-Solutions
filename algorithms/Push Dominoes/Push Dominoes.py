class Solution:
    def pushDominoes(self, dom: str) -> str:
        from collections import deque
        n = len(dom)
        d = set()
        q = deque()
        arr = [0 for i in range(n)]
        for i in range(n):
            if dom[i] == "L":
                arr[i] = -1
                d.add(i)
                q.append((i,"L"))
            if dom[i] == "R":
                arr[i] = 1
                d.add(i)
                q.append((i,"R"))
        while q:
            t1 = set()
            for _ in range(len(q)):
                t = q.popleft()
                if t[1] == "L":
                    if t[0]-1 >= 0 and t[0]-1 not in d:
                        t1.add(t[0]-1)
                        arr[t[0]-1] -= 1
                else:
                    if t[0]+1 < n and t[0]+1 not in d:
                        t1.add(t[0]+1)
                        arr[t[0]+1] += 1
            for val in t1:
                d.add(val)
                if arr[val] > 0:
                    q.append((val,"R"))
                elif arr[val]<0:
                    q.append((val,"L"))
        ans = ""
        for val in arr:
            if val<0:
                ans += "L"
            elif val>0:
                ans += "R"
            else:
                ans += "."
        return ans
