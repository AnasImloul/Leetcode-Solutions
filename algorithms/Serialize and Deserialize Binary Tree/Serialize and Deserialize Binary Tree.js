/**
 * Encodes a tree to a single string.
 *
 * @param {TreeNode} root
 * @return {string}
 */
 var serialize = function(root) {
  let result = [];
  const dfs = (r) => {
    if (!r) {
      result.push('N');
      return;
    }
    result.push(r.val);
    dfs(r.left);
    dfs(r.right);
  }
  dfs(root);
  return result.join(",")
};

/**
 * Decodes your encoded data to tree.
 *
 * @param {string} data
 * @return {TreeNode}
 */
var deserialize = function(data) {
  const vals = data.split(",");
  const dfs = (stream) => {
    const item = stream.shift();
    if (item == 'N') {
      return null;
    }
    const node = new TreeNode(item);
    node.left = dfs(stream);
    node.right = dfs(stream);
    return node;
  };

  return dfs(vals);
};
