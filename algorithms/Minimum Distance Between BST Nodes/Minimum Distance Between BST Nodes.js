/**
 * @param {TreeNode} root
 * @return {number}
 */
var minDiffInBST = function(root) {
    let arr = [];
    
	const helper = (node) => {
		if (node) {
			helper(node.left);
			arr.push(node.val);
			helper(node.right);
		}
	}
	helper(root);
    
	let min = Infinity;
	for (let i = 0; i < arr.length - 1; i++) {
		const diff = Math.abs(arr[i] - arr[i + 1]);
		min = Math.min(min, diff);
	}
    
	return min;
};
