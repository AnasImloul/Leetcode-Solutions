# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def traverse(self,node,index,n):
        res = []
        if not node: 
            index[0] -= 1
            return True,[]
        
        # when we reach the end of voyage but still node is present
        if node and index[0] == n : return False,[]
        
        #print('Here node = ',node.val, 'Index = ',index[0] , 'voyage val is',self.voyage[index[0]])
        
        # if node.val is not same as voyage[index] in preorder traverse
        if node.val != self.voyage[index[0]] : return False,[]
        
        if not node.left and not node.right : return True , []
        
        # for traversing first check if node.left is voyage[index+1] or node.right or None
        old = index[0]
        
        # try left and right
        index[0] = index[0] + 1
        a,l1 = self.traverse(node.left,index,n)
        index[0] = index[0] + 1
        b,l2 = self.traverse(node.right,index,n)
        #print('node =',node.val,'  left1 =',a,' and right1 =',b)
        if a and b :
            res = []
            for i in l1: res.append(i)
            for i in l2: res.append(i)
            return True , res
        
        #try right and left
        index[0] = old
        index[0] = index[0] + 1
        a,l1 = self.traverse(node.right,index,n)
        index[0] = index[0] + 1
        b,l2 = self.traverse(node.left,index,n) 
        #print('node =',node.val,'   left2 =',b,' and right2 =',a)
        if a and b :
            res = []
            res.append(node.val)
            for i in l1: res.append(i)
            for i in l2: res.append(i)
            return True , res
        
        return False,[]
    
    def flipMatchVoyage(self, root: Optional[TreeNode], voyage: List[int]) -> List[int]:
        self.voyage = voyage
        ans , lst = self.traverse(root,[0],len(voyage))
        if ans == False : return [-1]
        return lst
