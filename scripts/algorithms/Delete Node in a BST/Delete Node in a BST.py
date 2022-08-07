
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:

def find_inorder(root, key):

	if root is None :
		return []

	return find_inorder(root.left, key) + [root.val] + find_inorder(root.right, key)

def find_preorder(root, key):

	if root is None:
		return []

	return [root.val] + find_preorder(root.left,key) + find_preorder(root.right, key)

preorder = find_preorder(root, key)

try:
	preorder.remove(key)
except:
	return root

inorder = find_inorder(root, key)

inorder.remove(key)




hashmap = {}

for i in range(len(inorder)):
	key = inorder[i]
	hashmap[key] = i

def buildTree(left, right):

	if left > right:
		return 

	val = inorder[left]
	root = TreeNode(val)

	index = hashmap[val]

	root.left = buildTree(left, index-1)
	root.right = buildTree(index+1, right)

	return root

N = len(inorder)
new_tree = buildTree(0,N-1)

return new_tree


