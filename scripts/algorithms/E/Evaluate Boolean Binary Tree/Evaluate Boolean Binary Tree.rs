// Runtime: 3 ms (Top 80.0%) | Memory: 2.30 MB (Top 70.0%)

type Node = Option<std::rc::Rc<std::cell::RefCell<TreeNode>>>;
impl Solution {
    pub fn evaluate_tree(root: Node) -> bool {
        Self::dfs(root)
    }
    fn dfs(n: Node) -> bool {
        let node = n.as_ref().unwrap().borrow();
        
        match node.val {
            0 =>  false,
            1 =>  true,
            2 =>  Self::dfs(node.right.clone()) || Self::dfs(node.left.clone()),
            _ =>  Self::dfs(node.right.clone()) && Self::dfs(node.left.clone()),
        }
    }
}
