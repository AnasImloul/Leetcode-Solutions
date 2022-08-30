// Runtime: 173 ms (Top 6.43%) | Memory: 52.7 MB (Top 31.75%)
var pathSum = function(root, targetSum) {
  const paths = [];

  function dfs(root, sum, curr = []) {
    if (!root) return;

    const newCurr = [...curr, root.val];
    if (!root.left && !root.right && sum === root.val) return paths.push(newCurr);

    dfs(root.left, sum - root.val, newCurr);
    dfs(root.right, sum - root.val, newCurr);
  }

  dfs(root, targetSum);
  return paths;
};