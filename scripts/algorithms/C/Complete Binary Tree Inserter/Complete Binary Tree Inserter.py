// Runtime: 44 ms (Top 99.57%) | Memory: 18.50 MB (Top 5.17%)

from collections import deque

class CBTInserter:

    
    def __init__(self, root: TreeNode):
        
        self.root = root
        
        self.parent_keeper = deque([root])

        while True:
            
            cur = self.parent_keeper[0]
            
            if cur:
                
                if cur.left:
                    
                    self.parent_keeper.append( cur.left )
                    
                    if cur.right:
                        
                        self.parent_keeper.append( cur.right )
                        
                        # cur is completed with two child, pop out
                        self.parent_keeper.popleft()
                    
                    else:
                        # parent of next insertion is found, stop
                        break
                
                else:
                    # parent of next insertion is found, stop
                    break
        
        

    def insert(self, v: int) -> int:
        
        parent = self.parent_keeper[0]
        
		# Insert with leftward compact, to meet the definition of complete binary tree
		
        if not parent.left:
            parent.left = TreeNode( v )
            self.parent_keeper.append( parent.left )
        else:
            parent.right = TreeNode( v )
            self.parent_keeper.append( parent.right )
            
            # current parent is completed with two child now, pop parent from parent keeper on the head
            self.parent_keeper.popleft()
            
        return parent.val
        

    def get_root(self) -> TreeNode:
        
        return self.root
