# Runtime: 2457 ms (Top 91.30%) | Memory: 66.7 MB (Top 52.17%)
class Solution:
    def canMerge(self, trees: List[TreeNode]) -> TreeNode:
        n = len(trees)
        if n == 1: return trees[0]

        value_to_root = {} # Map each integer root value to its node
        appeared_as_middle_child = set() # All values appearing in trees but not in a curr or leaf
        self.saw_conflict = False # If this is ever true, break out of function and return None
        leaf_value_to_parent_node = {}

        def is_leaf_node(curr: TreeNode) -> bool:
            return curr.left is None and curr.right is None

        def get_size(curr: TreeNode) -> int: # DFS to count Binary Tree Size
            if curr is None: return 0
            return 1 + get_size(curr.left) + get_size(curr.right)

        def is_valid_bst(curr: TreeNode, lo=-math.inf, hi=math.inf) -> bool: # Standard BST validation code
            if curr is None: return True
            return all((lo < curr.val < hi,
                        is_valid_bst(curr.left, lo, curr.val),
                        is_valid_bst(curr.right, curr.val, hi)))

        def process_child(child_node: TreeNode, parent: TreeNode) -> None:
            if child_node is None:
                return None
            elif child_node.val in leaf_value_to_parent_node or child_node.val in appeared_as_middle_child:
                self.saw_conflict = True # Already saw this child node's value in a non-root node
            elif is_leaf_node(child_node):
                leaf_value_to_parent_node[child_node.val] = parent
            elif child_node.val in value_to_root:
                self.saw_conflict = True
            else:
                appeared_as_middle_child.add(child_node.val)
                process_child(child_node.left, child_node)
                process_child(child_node.right, child_node)

        def process_root(curr_root: TreeNode) -> None:
            value_to_root[curr_root.val] = curr_root

            if curr_root.val in appeared_as_middle_child:
                self.saw_conflict = True
            else:
                process_child(curr_root.left, curr_root)
                process_child(curr_root.right, curr_root)

        for root_here in trees:
            process_root(root_here)
            if self.saw_conflict: return None

        final_expected_size = len(leaf_value_to_parent_node) + len(appeared_as_middle_child) + 1

        final_root = None # The root of our final BST will be stored here
        while value_to_root:
            root_val, root_node_to_move = value_to_root.popitem()

            if root_val not in leaf_value_to_parent_node: # Possibly found main root
                if final_root is None:
                    final_root = root_node_to_move
                else:
                    return None # Found two main roots
            else:
                new_parent = leaf_value_to_parent_node.pop(root_val)
                if new_parent.left is not None and new_parent.left.val == root_val:
                    new_parent.left = root_node_to_move
                    continue
                elif new_parent.right is not None and new_parent.right.val == root_val:
                    new_parent.right = root_node_to_move
                else:
                    return None # Didn't find a place to put this node

        # Didn't find any candidates for main root, or have a cycle, or didn't use all trees
        if final_root is None or not is_valid_bst(final_root) or get_size(final_root) != final_expected_size:
            return None

        return final_root