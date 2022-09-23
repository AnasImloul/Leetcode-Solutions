# Runtime: 111 ms (Top 6.54%) | Memory: 14.1 MB (Top 35.32%)
class UnionFind:
    def __init__(self,n):
        self.tot_components = n
        self.parent = [-1] * n
        self.rank = [0] * n

    def find(self,node):
        if self.parent[node] == -1:
            return node
        self.parent[node] = self.find(self.parent[node])
        return self.parent[node]

    def union(self,node1,node2):
        node1_p = self.find(node1)
        node2_p = self.find(node2)

        if node1_p == node2_p:
            return True
        else:
            if self.rank[node1_p] < self.rank[node1_p]:
                self.parent[node1_p] = node2_p
            elif self.rank[node1_p] > self.rank[node1_p]:
                self.parent[node2_p] = node1_p
            else:
                self.parent[node1_p] = node2_p
                self.rank[node2_p] += 1
            self.tot_components -= 1
            return False

class Solution:
    def equationsPossible(self, equations: List[str]) -> bool:

        uf = UnionFind(26)

        for eqn in equations:
            if eqn[1] == "=":
                uf.union(ord(eqn[0])-ord("a"),ord(eqn[3])-ord("a"))

        for eqn in equations:
            if eqn[1] == "!":
                if uf.find(ord(eqn[0])-ord("a")) == uf.find(ord(eqn[3])-ord("a")):
                    return False
        return True