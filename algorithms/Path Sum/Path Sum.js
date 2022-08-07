var hasPathSum = function(root, targetSum) {
	return DFS(root, 0 , targetSum)
};

const DFS = (curr, currentSum, targetSum) =>{

	if(!curr) return false

	currentSum += curr.val;

	if(!curr.left && !curr.right) return currentSum === targetSum;

	return DFS(curr.left, currentSum, targetSum) || DFS(curr.right, currentSum, targetSum)
}
