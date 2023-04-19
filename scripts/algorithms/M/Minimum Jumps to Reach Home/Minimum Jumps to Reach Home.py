class Solution:
    def minimumJumps(self, fb: List[int], a: int, b: int, x: int) -> int:
        fb = set(fb)
        q = deque([[0,0,True]])
        while(q):
            n,l,isf = q.popleft()
            if(n<0 or n in fb or n>2000+2*b):
                continue
            fb.add(n)
            if(n==x):
                return l
            if isf and n-b>0:
                q.append([n-b,l+1,False])                
            q.append([n+a,l+1,True])
        return -1