class Solution:
    def constructFromPrePost(self, preorder: List[int], postorder: List[int]) -> Optional[TreeNode]:

        def build(preorder, preStart, preEnd, postorder, postStart, postEnd):
            if preStart > preEnd:
                return
            elif preStart == preEnd:
                return TreeNode(preorder[preStart])
            
            rootVal = preorder[preStart]
            leftRootVal = preorder[preStart + 1]
            index = valToIndex[leftRootVal]
            root = TreeNode(rootVal)
            leftSize = index - postStart + 1
            
            root.left = build(preorder, preStart + 1, preStart + leftSize,
postorder, postStart, index)
            root.right = build(preorder, preStart + leftSize + 1, preEnd,
postorder, index + 1, postEnd - 1)
            
            return root
        
        valToIndex = {}
        for i in range(len(postorder)):
            valToIndex[postorder[i]] = i
        
        return build(preorder, 0, len(preorder) - 1, postorder, 0, len(postorder) - 1)
