class Solution:
    def getCoprimes(self, nums: List[int], edges: List[List[int]]) -> List[int]:
        
        gcdset = [set() for i in range(51)]
        for i in range(1,51):
            for j in range(1,51):
                if math.gcd(i,j) == 1:
                    gcdset[i].add(j)
                    gcdset[j].add(i)
        
        graph = defaultdict(list)
        for v1, v2 in edges:
            graph[v1].append(v2)
            graph[v2].append(v1)
        
        ans = [-1]*len(nums)
        q = [[0, {}]]
        seen = set([0])
        depth = 0
        while q:
            temp = []
            for node, ancestors in q:
                index_depth = (-1,-1)
                for anc in list(ancestors.keys()):
                    if anc in gcdset[nums[node]]:
                        index, d = ancestors[anc]
                        if d > index_depth[1]:
                            index_depth = (index,d)
                ans[node] = index_depth[0]
                
                copy = ancestors.copy()
                copy[nums[node]] = (node,depth)
                
                for child in graph[node]:
                    if child not in seen:
                        seen.add(child)
                        temp.append([child, copy])
            q = temp
            depth += 1
        return ans
