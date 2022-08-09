class Solution:
    def formNodes(self,nums, l,r):
        if l > r:
            return None
        else:
            mid = l+(r-l)//2
            node = TreeNode(nums[mid])
            node.left = self.formNodes(nums, l,mid-1)
            node.right = self.formNodes(nums, mid+1,r)
            return node
        
        
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        return self.formNodes(nums, 0,len(nums)-1)
