class Trie:
    def __init__(self):
        self.root = {}
        
    def add(self, word):
        cur = self.root
        for c in word:
            if c not in cur:
                cur[c] = {}
            cur = cur[c]
            
    def find(self, word):
        cur = self.root
        res = ""
        for c in word:
            desired = "1" if c == "0" else "0"
            if not desired in cur:
                desired = c
            res += desired
            cur = cur[desired]
        return res
    
    def delete(self, word):
        cur = self.root
        path = []
        for c in word:
            path.append(cur)
            cur = cur[c]
        for c, obj in zip(word[::-1], path[::-1]):
            if not obj[c]:
                del obj[c]
            else:
                break
        
    
class Solution:
    def maxGeneticDifference(self, parents: List[int], queries: List[List[int]]) -> List[int]:
        #since max(10^5,2*10^5) < 2^18, 18 bits are enough to represent a value or node as a bit string 
        def makebin(x):
            return bin(x)[2:].zfill(18)
        node_queries = defaultdict(list)
        for i, (node, val) in enumerate(queries):
            node_queries[node].append((i,val))
        graph = defaultdict(list)
        for y, x in enumerate(parents):
            graph[x].append(y)
        res = [-1 for _ in queries]
        tree = Trie()
        #dfs traversal
        #during the traversal, it is making bit Trie using the nodes from the root to the current node of the graph
        def dfs(v):
            v_bin = makebin(v)
            tree.add(v_bin)
            for i, val in node_queries[v]:
                val_bin = makebin(val)
                target_bin = tree.find(val_bin)
                res[i] = int(target_bin,2)^val
            for w in graph[v]:
                dfs(w)
            tree.delete(v_bin)
        dfs(graph[-1][0]) #dfs from the root
        return res
            
