class Solution:
	def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
		if not nums:
			return None
		m = max(nums)
		idx  = nums.index(m)
		root = TreeNode(m)
		root.left = self.constructMaximumBinaryTree(nums[:idx])
		root.right = self.constructMaximumBinaryTree(nums[idx+1:])
		return root