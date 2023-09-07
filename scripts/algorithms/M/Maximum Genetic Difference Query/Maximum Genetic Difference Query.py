# Runtime: 6663 ms (Top 46.4%) | Memory: 339.09 MB (Top 7.1%)

class Solution:
    def maxGeneticDifference(self, parents: List[int], queries: List[List[int]]) -> List[int]:
        adj_map = collections.defaultdict(set)
        root = None
        for i, node in enumerate(parents):
            if node == -1:
                root = i
            else:
                adj_map[node].add(i)
        queries_map = collections.defaultdict(set)

        for q in queries:
            queries_map[q[0]].add(q[1])
        self.res_map = {}
        def helperDFS(curr_root,prefix_map):

            if curr_root in queries_map:
                for val in queries_map[curr_root]:
                    bin_rep = format(val, '020b')
                    best_bin = ""
                    print(bin_rep)
                    for i in range(20):
                        if prefix_map[best_bin+str(1-int(bin_rep[i]))]:
                            best_bin += str(1-int(bin_rep[i]))
                        else:
                            best_bin += bin_rep[i]
                    self.res_map[(curr_root,val)] = int(best_bin,2) ^ val 
            for child in adj_map[curr_root]:
                bin_rep = format(child, '020b')
                for i in range(1, len(bin_rep)+1):
                    prefix_map[bin_rep[0:i]].add(child)
                helperDFS(child, prefix_map)
                for i in range(1, len(bin_rep)+1):
                    prefix_map[bin_rep[0:i]].remove(child)

        initial_prefixmap = collections.defaultdict(set)
        root_rep = format(root, '020b')
        for i in range(1,21):
            initial_prefixmap[root_rep[0:i]].add(root)
        helperDFS(root, initial_prefixmap)
        res = []
        for q in queries:
            res.append(self.res_map[(q[0],q[1])])
        return res
            
