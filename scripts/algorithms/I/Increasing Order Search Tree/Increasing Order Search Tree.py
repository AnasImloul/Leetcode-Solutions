# Runtime: 22 ms (Top 13.1%) | Memory: 13.44 MB (Top 40.5%)

class Solution(object):
    
    def increasingBST(self, root):
        
        def sortBST(node):
            if not node:    return []
            
            # return the in order BST nodes in list
            return sortBST(node.left) + [node.val] + sortBST(node.right)
            
        # the in order sorted list of the tree nodes
        sorted_list = sortBST(root)
        
        # generate new tree: temp for update, ans for return the root
        ans = temp = TreeNode(sorted_list[0])
        
        # insert nodes to the right side of the new tree
        for i in range(1, len(sorted_list)):
            temp.right = TreeNode(sorted_list[i])
            temp = temp.right
            
        return ans