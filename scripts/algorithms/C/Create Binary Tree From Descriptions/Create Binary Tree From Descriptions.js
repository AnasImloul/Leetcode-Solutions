// Runtime: 516 ms (Top 87.84%) | Memory: 88.6 MB (Top 39.19%)
var createBinaryTree = function(descriptions) {
  let nodes = new Map(), children = new Set();
  for (let [parent, child, isLeft] of descriptions) {
    let parentNode = nodes.get(parent) || new TreeNode(parent);
    if (!nodes.has(parent)) nodes.set(parent, parentNode);

    let childNode = nodes.get(child) || new TreeNode(child);
    if (!nodes.has(child)) nodes.set(child, childNode);

    if (isLeft) parentNode.left = childNode;
    else parentNode.right = childNode;

    children.add(child);
  }

  for (let [parent, child, isLeft] of descriptions) {
    // a node with no parent is the root
    if (!children.has(parent)) return nodes.get(parent);
  }
};