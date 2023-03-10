var bstFromPreorder = function(preorder) {
  let head = new TreeNode(preorder[0]);
  for (let i = 1, curr; i<preorder.length; i++) {
     curr = head;
     while (1) {
        if (preorder[i]>curr.val) 
          if (curr.right !=null) { curr = curr.right; }
          else { curr.right = new TreeNode(preorder[i]); break; }
        else
          if (curr.left !=null) { curr = curr.left; }
          else { curr.left = new TreeNode(preorder[i]); break; }
     } 
  } 
  return head;  
};