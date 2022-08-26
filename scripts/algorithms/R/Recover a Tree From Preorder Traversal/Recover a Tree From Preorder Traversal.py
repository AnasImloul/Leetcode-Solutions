// Runtime: 138 ms (Top 42.81%) | Memory: 14.7 MB (Top 52.51%)
class Solution:
    def recoverFromPreorder(self, traversal: str) -> Optional[TreeNode]:
        i = 0
        dummy_head = TreeNode()
        depth = 0
        while i < len(traversal):
            if traversal[i].isdigit():
                value, i = get_value(traversal, i)
                insert_node(dummy_head, depth, value)

            else:
                depth, i = get_depth(traversal, i)

        return dummy_head.left

# Returns the next value from the string traversal, and returns the position following the last digit of the current value.
def get_value(traversal, i):
    value = 0
    while i < len(traversal) and traversal[i].isdigit():
        value *= 10
        value += int(traversal[i])
        i += 1

    return value, i

# Insertes a node of the given `value` at the given `depth` of the subtree whose root is the given `root`.
def insert_node(root, depth, value):
    for _ in range(depth):
        if root.right:
            root = root.right
        else:
            root = root.left

    new_node = TreeNode(value)
    if root.left:
        root.right = new_node
    else:
        root.left = new_node

# Gets the next depth from the string traversal, and returns the position following the last dash of the current depth.
def get_depth(traversal, i):
    depth = 0
    while i < len(traversal) and traversal[i] == "-":
        depth += 1
        i += 1

    return depth, i