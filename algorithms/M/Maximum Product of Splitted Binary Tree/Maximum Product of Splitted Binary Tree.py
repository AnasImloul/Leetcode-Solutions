class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        def findTotalSum(node, totalSum):
            if node is None:
                return totalSum
            totalSum = findTotalSum(node.left,totalSum)
            totalSum += node.val
            totalSum = findTotalSum(node.right,totalSum)
            return totalSum
        
        def dfs(node,maxProd,totalSum):
            if node is None:
                return maxProd,0
            if not node.left and not node.right:
                return maxProd,node.val
            maxProd, lSum = dfs(node.left,maxProd,totalSum)
            maxProd, rSum = dfs(node.right,maxProd,totalSum)
            subTreeSum = lSum+rSum+node.val
            maxProd = max(maxProd,(totalSum-lSum)*lSum,(totalSum-rSum)*rSum,(totalSum-subTreeSum)*subTreeSum)
            return maxProd, subTreeSum
        
        totalSum = findTotalSum(root, 0)
        product,_ = dfs(root,1,totalSum)
        return product % (pow(10,9)+7)
