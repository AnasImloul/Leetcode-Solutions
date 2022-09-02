// Runtime: 113 ms (Top 25.04%) | Memory: 44.6 MB (Top 16.66%)
var levelOrder = function(root) {
  const result = [];
  if (root == null) return result

  let lvl = 0;
  let temp = [];
  let q = new Queue();
  q.enqueue(root)

  while (!q.isEmpty()) {
    let levelSize = q.size();
    while (levelSize-- != 0) {
      let node = q.dequeue()
      temp.push(node.val)
      // enqueue both children first,
      // before looking at the next dequeued item
      if (node.left != null) q.enqueue(node.left);
      if (node.right != null) q.enqueue(node.right);
    }
    result.push(temp);
    temp = [];
    lvl +=1
  }

  return result
};