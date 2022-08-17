
class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        hashmap = {}
        nodes = set()
        children = set()
        for parent,child,isLeft in descriptions:
            nodes.add(parent)
            nodes.add(child)
            children.add(child)
            if parent not in hashmap:
                hashmap[parent] = TreeNode(parent)
            if child not in hashmap:
                hashmap[child] = TreeNode(child)
            if isLeft:
                hashmap[parent].left = hashmap[child]
            if not isLeft:
                hashmap[parent].right = hashmap[child]
        
        for node in nodes:
            if node not in children:
                return hashmap[node]



