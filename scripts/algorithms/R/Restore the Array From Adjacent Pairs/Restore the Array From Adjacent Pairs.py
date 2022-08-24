// Runtime: 2248 ms (Top 15.65%) | Memory: 166 MB (Top 35.87%)
class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        # create the map
        adj = collections.defaultdict(list)
        for a, b in adjacentPairs:
            adj[a].append(b)
            adj[b].append(a)

        # find the start num
        start = adjacentPairs[0][0]
        for k, v in adj.items():
            if len(v) ==1:
                start = k
                break

        # dfs to connect the graph
        nums=[]
        seen = set()
        def dfs(num):
            seen.add(num)
            for next_num in adj[num]:
                if next_num in seen: continue
                dfs(next_num)
            nums.append(num)
        dfs(start)
        return nums
