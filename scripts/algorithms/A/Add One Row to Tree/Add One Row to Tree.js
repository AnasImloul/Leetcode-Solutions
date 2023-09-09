// Runtime: 81 ms (Top 52.6%) | Memory: 48.75 MB (Top 19.3%)

/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} val
 * @param {number} depth
 * @return {TreeNode}
 */
var addOneRow = function(root, val, depth) {
	if (depth === 1) return new TreeNode(val, root);

	const refactor = (node = root, currentDep = 1) => {
		if (!node) return;
		if (currentDep === depth - 1) {
			const { left, right } = node;
			node.left = new TreeNode(val, left);
			node.right = new TreeNode(val, null, right);
		}
		refactor(node.left, currentDep + 1);
		refactor(node.right, currentDep + 1);
	};
	refactor();
	return root;
};