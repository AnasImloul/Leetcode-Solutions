class Solution:
    def largestComponentSize(self, nums: List[int]) -> int:
        
        def find(node):
            if parent[node] == -1: return node
            else:
                parent[node] = find(parent[node])
                return parent[node]
        
        def union(idx1,idx2):
            par1,par2 = find(idx1),find(idx2)
            if par1!=par2:
                if rank[par1] > rank[par2]:
                    parent[par2] = par1
                elif rank[par2] > rank[par1]:
                    parent[par1] = par2
                else:
                    parent[par2] = par1
                    rank[par1] += 1
        
        n = len(nums)
        parent = defaultdict(lambda:-1)
        rank = defaultdict(lambda:0)
        for i in range(n):
            limit = int(nums[i]**0.5)
            for j in range(2,limit+1):
                if nums[i] % j == 0:
                    union(nums[i],j)
                    union(nums[i],nums[i]//j)
        count = defaultdict(lambda:0)
        best = -1
        for num in nums:
            par = find(num)
            tmp = count[par] + 1
            if tmp > best: best = tmp
            count[par] = tmp
        return best
