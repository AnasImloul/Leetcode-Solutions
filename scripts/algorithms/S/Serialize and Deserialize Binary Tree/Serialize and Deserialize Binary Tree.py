# Runtime: 372 ms (Top 18.39%) | Memory: 20.4 MB (Top 30.28%)
class Codec:

    def serialize(self, root):
        if not root: return 'N'

        left = self.serialize(root.left)
        right = self.serialize(root.right)

        return ','.join([str(root.val), left, right])

    def deserialize(self, data):
        data = data.split(',')
        root = self.buildTree(data)
        return root

    def buildTree(self, data):
        val = data.pop(0)
        if val == 'N': return None
        node = TreeNode(val)
        node.left = self.buildTree(data)
        node.right = self.buildTree(data)
        return node