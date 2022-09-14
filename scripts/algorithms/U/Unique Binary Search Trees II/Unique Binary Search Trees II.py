# Runtime: 73 ms (Top 74.11%) | Memory: 15.7 MB (Top 42.55%)
# Definition for a binary tree node.
# class TreeNode:
# def __init__(self, val=0, left=None, right=None):
# self.val = val
# self.left = left
# self.right = right
class Solution:

    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        # define a sorted list of the numbers, for each num in that list , leftvalues
# are left tree and right val are rightree, then for each number create a tree
# assign the left and right to that root and append the root to the ans
        nums = list(range(1,n+1))
        def dfs(nums):
            if not nums:
                return [None]
            ans = []
            for i in range(len(nums)):
                leftTrees = dfs(nums[:i])
                rightTrees = dfs(nums[i+1:])

                for l in leftTrees:
                    for r in rightTrees:
                        root = TreeNode(nums[i])
                        root.left = l
                        root.right = r
                        ans.append(root)
            return ans

        return dfs(nums)
