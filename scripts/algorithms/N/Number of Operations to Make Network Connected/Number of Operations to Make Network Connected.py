# Runtime: 772 ms (Top 55.10%) | Memory: 34.3 MB (Top 72.08%)
class Solution(object):
    def __init__(self):
        self.parents = []
        self.count = []

    def makeConnected(self, n, connections):
        """
        :type n: int
        :type connections: List[List[int]]
        :rtype: int
        """
        if len(connections) < n-1:
            return -1
        self.parents = [i for i in range(n)]
        self.count = [1 for _ in range(n)]
        for connection in connections:
            a, b = connection[0], connection[1]
            self.union(a, b)
        return len({self.find(i) for i in range(n)}) - 1

    def find(self, node):
        """
        :type node: int
        :rtype: int
        """
        while(node != self.parents[node]):
            node = self.parents[node];
        return node

    def union(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: None
        """
        a_parent, b_parent = self.find(a), self.find(b)
        a_size, b_size = self.count[a_parent], self.count[b_parent]

        if a_parent != b_parent:
            if a_size < b_size:
                self.parents[a_parent] = b_parent
                self.count[b_parent] += a_size
            else:
                self.parents[b_parent] = a_parent
                self.count[a_parent] += b_size