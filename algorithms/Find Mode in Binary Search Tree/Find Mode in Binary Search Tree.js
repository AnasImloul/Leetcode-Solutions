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
 * @return {number[]}
 */
var findMode = function(root) {
	const dup = new Map();

	helper(root, dup);

	let res = [];
	let max = Number.MIN_VALUE;
	for(const [key, value] of dup) {
		if (value > 1 && value >= max) {
			res.push(key);
			max = Math.max(max, value);
		}
	}

	return res.length > 0 ? res : [...dup.keys()];
};

function helper(root, dup) {
	if(root !== null) {
		dup.set(root.val, ~~dup.get(root.val) + 1);
		helper(root.left, dup);
		helper(root.right, dup);
	}
}