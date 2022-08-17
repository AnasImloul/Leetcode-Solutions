We can't create Full Binary tree with even number of nodes. e.g n = 2/4/6/8...
start with cache having n = 1
	cache = {1:TreeNode()}
	
	n = 3
							0 (root)
						 1     1
	n = 5       
	                        0 (root1)                  0 (root2) 
						 1     3                     3    1
	n = 7  
	                         0                    0                   0
						 1      5              3    3              5     1


class Solution:
    def allPossibleFBT(self, n: int) -> List[Optional[TreeNode]]:
        def helper(n):
            if n in cache:
                return cache[n]
            # We use result array to store all possible binary tree of size n
            result = [] 
            leftNodes, rightNodes = 1,n-2
            # if n = 7 then, (leftNodes,rightNodes) should be : (1,5),(3,3),(5,1) 
            while rightNodes >0:
                root = TreeNode()
                if leftNodes not in cache:
                    helper(leftNodes)
                if rightNodes not in cache:
                    helper(rightNodes)
                leftTree = cache[leftNodes]
                rightTree = cache[rightNodes]
                # Using two for loops we generate all possible binary tree.
                # Always remember root of each binary tree is diffrent, So create new root every time
                for i in range(len(leftTree)):
                    for j in range(len(rightTree)):
                        root.left = leftTree[i]
                        root.right = rightTree[j]
                        result.append(root)
                        root = TreeNode()
                leftNodes += 2
                rightNodes -= 2
            cache[n] = result
            return result
            
        if n % 2 == 0:
            return 
        else:
            cache = {1:[TreeNode()]}
            return helper(n)
			
Thank You 😊

