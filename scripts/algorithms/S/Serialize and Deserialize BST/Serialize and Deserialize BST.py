class Codec:
    def serialize(self, root: Optional[TreeNode]) -> str:
        """Encodes a tree to a single string.
        """
        if not root:
            return ""
        res = []
        def dfs(node):
            res.append(str(node.val))
            if node.left:
                dfs(node.left)
            if node.right:
                dfs(node.right)
        dfs(root)
        return ','.join(res)
    def deserialize(self, data: str) -> Optional[TreeNode]:
        """Decodes your encoded data to tree.
        """
        if len(data) == 0:
            return []
        splitdata = data.split(",") 
        preorder = []
        for item in splitdata:
            preorder.append(int(item))          
        inorder = sorted(preorder)
        hash_map = {}  
        for i in range(len(inorder)):
            hash_map[inorder[i]] = i
        def helper(preorder, pstart, pend, inorder, istart, iend):
            if pstart > pend:
                return None
            elif pstart == pend:
                return TreeNode(preorder[pstart])

            root = TreeNode(preorder[pstart])
            
            rootindex = hash_map[preorder[pstart]]
            
            numleft = rootindex - istart
            
            root.left = helper(preorder, pstart+1, pstart + numleft, inorder, istart,rootindex-1 )
            root.right = helper(preorder, pstart + numleft +1, pend, inorder, rootindex +1, iend)
            
            return root
            
        return (helper(preorder, 0, len(preorder)-1, inorder, 0, len(inorder)-1))
