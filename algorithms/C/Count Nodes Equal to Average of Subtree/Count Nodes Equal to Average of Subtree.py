class Solution:
    def averageOfSubtree(self, root: Optional[TreeNode]) -> int:
        
        
        def calculate_average(root):
            if root:
                self.summ+=root.val
                self.nodecount+=1
                calculate_average(root.left)
                calculate_average(root.right)
        
        
        def calculate_for_each_node(root):
            if root:
                self.summ = 0
                self.nodecount = 0
                calculate_average(root)
                if ((self.summ)//(self.nodecount)) == root.val:
                    self.count+=1 
                calculate_for_each_node(root.left)
                calculate_for_each_node(root.right)
                
                
        self.count = 0
        calculate_for_each_node(root)       
        return self.count

