class Solution:
    def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
        
        class UnionFind:
            def __init__(self):
                self.parents = {}
                self.ranks = {}
                
            def insert(self, x):
                if x not in self.parents:
                    self.parents[x] = x
                    self.ranks[x] = 0
                
            def find_parent(self, x):
                if self.parents[x] != x:
                    self.parents[x] = self.find_parent(self.parents[x])
                return self.parents[x]
            
            def union(self, x, y):
                self.insert(x)
                self.insert(y)
                x, y = self.find_parent(x), self.find_parent(y)
                if x == y:
                    return 
                if self.ranks[x] > self.ranks[y]:
                    self.parents[y] = x
                else:
                    self.parents[x] = y
                    if self.ranks[x] == self.ranks[y]:
                        self.ranks[y] += 1
            
        time2meets = defaultdict(list)
        for x, y, t in meetings:
            time2meets[t].append((x, y))
        time2meets = sorted(time2meets.items())
 
        curr_know = set([0, firstPerson])

        for time, meets in time2meets:
            uf = UnionFind()
            for x, y in meets:
                uf.union(x, y)
            
            groups = defaultdict(set)
            for idx in uf.parents:
                groups[uf.find_parent(idx)].add(idx)
            
            for group in groups.values():
                if group & curr_know:
                    curr_know.update(group)

        return list(curr_know)
