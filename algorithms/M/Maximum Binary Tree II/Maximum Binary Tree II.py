class Solution:
    """
    approach:
    given a, we can get the inorder traversal of it, then append val to it and
    then construct the tree back
    """
    def insertIntoMaxTree(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        inorder_list = []
        def inorder(root):
            if not root:
                return
            inorder(root.left)
            inorder_list.append(root.val)
            inorder(root.right)
            
        inorder(root)
        inorder_list.append(val)
        
        def get_maximum(val_list):
            max_index = -1
            max_val = -1
            for i, val in enumerate(val_list):
                if val > max_val:
                    max_val = val
                    max_index = i
            return max_index, max_val
                
        def create_tree(val_list):
            if not len(val_list):
                return None
            index, val = get_maximum(val_list)
            node = TreeNode(val)
            node.left = create_tree(val_list[:index])
            node.right = create_tree(val_list[index+1:])
            return node
        
        b = create_tree(inorder_list)
        return b
