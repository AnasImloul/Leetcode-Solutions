var serialize = function (root) {
  if (!root) return "";
  let res = [];

  function getNode(node) {
    if (!node) {
      res.push("null");
    } else {
      res.push(node.val);
      getNode(node.left);
      getNode(node.right);
    }
  }

  getNode(root);

  return res.join(",");
};

/**
 * Decodes your encoded data to tree.
 *
 * @param {string} data
 * @return {TreeNode}
 */
var deserialize = function (data) {
  if (data === "") return null;
  const arr = data.split(",");

  function buildTree(array) {
    const nodeVal = array.shift();

    if (nodeVal === "null") return null;

    const node = new TreeNode(nodeVal);
    node.left = buildTree(array);  //build left first
    node.right = buildTree(array); //build right with updated array.

    return node;
  }

  return buildTree(arr);
};
