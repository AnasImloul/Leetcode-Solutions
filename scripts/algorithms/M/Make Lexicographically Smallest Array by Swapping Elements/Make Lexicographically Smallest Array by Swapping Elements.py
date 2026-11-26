# Runtime: 308 ms (Top 60.37%) | Memory: 48.80 MB (Top 50.82%)

class Solution:
    def lexicographicallySmallestArray(self, a: List[int], k: int) -> List[int]:
        b = []
        n = len(a)
        for i in range(n):
            b.append((a[i],i))
        b = sorted(b,key=lambda x: x[0])

        c = [[b[0]]]
        for i in range(1,n):
            if b[i][0]-b[i-1][0] <= k:
                c[-1].append(b[i])
            else:
                c.append([b[i]])
        for t in c:
            ind = []
            for x,y in t:
                ind.append(y)
            ind.sort()
            for i in range(len(ind)):
                a[ind[i]] = t[i][0]
        return a
