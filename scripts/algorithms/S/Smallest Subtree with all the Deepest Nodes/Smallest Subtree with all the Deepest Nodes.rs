// Runtime: 1 ms (Top 100.0%) | Memory: 2.20 MB (Top 100.0%)

use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    fn dfs(root: &Option<Rc<RefCell<TreeNode>>>) -> (i32, Option<Rc<RefCell<TreeNode>>>) {
        match root.clone() {
            Some(root_ref) => {
                let root_node = root_ref.borrow();

                let (left_height, left_tree) = Self::dfs(&root_node.left);
                let (right_height, right_tree) = Self::dfs(&root_node.right);

                if left_height > right_height {
                    (left_height + 1, left_tree)
                } else if right_height > left_height {
                    (right_height + 1, right_tree)
                } else {
                    (left_height + 1, root.clone())
                }
            }
            None => (0, None),
        }
    }

    pub fn subtree_with_all_deepest(
        root: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        Self::dfs(&root).1
    }
}
