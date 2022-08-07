class Solution:
    def arrayNesting(self, nums: List[int]) -> int:
        max_len = 0
        visited = set()
        def dfs(nums, index, dfs_visited):
            if index in dfs_visited:
                return len(dfs_visited)
            
            # add the index to dfs_visited and visited
            visited.add(index)
            dfs_visited.add(index)
            return dfs(nums, nums[index], dfs_visited)
            
        for i in range(len(nums)):
            if i not in visited:
                max_len = max(max_len, dfs(nums, i, set()))
        return max_len
