class DSU:
    def __init__(self):
        self.parentof = [-1 for _ in range(100001)]
        self.rankof = [1 for _ in range(100001)]

    def find(self,ele):
        def recur(ele):
            if self.parentof[ele]==-1: 
                return ele
            par = recur(self.parentof[ele])
            self.parentof[ele] = par
            return par
        return recur(ele)

    def unify(self,ele1,ele2):
        p1,p2 = self.find(ele1),self.find(ele2)
        r1,r2 = self.rankof[p1],self.rankof[p2]

        if p1==p2: return 
        if r1>r2:
            self.parentof[p2] = p1
        else:
            self.parentof[p1]=p2
            if r1==r2: self.rankof[p2]+=1

class Solution:
    def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
        dsu = DSU()
        nodes = set()
        smallest = [s[i] for i in range(len(s))]

        for i,j in pairs:
            dsu.unify(i,j)
            nodes.add(i)
            nodes.add(j)

        groups = {}
        for node in nodes:
            par = dsu.find(node)
            if par not in groups:
                groups[par] = [node]
            else:
                groups[par].append(node)
        
        for group in groups.values():
            letters,k = sorted([s[i] for i in group]),0
            
            for i in group:
                smallest[i] = letters[k]
                k+=1

        return "".join(smallest)
