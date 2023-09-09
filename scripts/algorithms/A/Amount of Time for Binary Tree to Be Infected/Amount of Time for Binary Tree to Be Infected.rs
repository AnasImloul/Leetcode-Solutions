// Runtime: 132 ms (Top 8.3%) | Memory: 33.80 MB (Top 33.3%)

use std::collections::{HashMap, HashSet, VecDeque};

/// @author: Leon
/// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/
/// Time Complexity:    O(V + E) ~ O(N)
/// Space Complexity:   O(V + E) ~ O(W)
/// Reference:
/// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/discuss/2456717/BFS-%2B-HashMap
impl Solution {
    pub fn amount_of_time(root: Option<Rc<RefCell<TreeNode>>>, start: i32) -> i32 {
        if let Some(rt) = root {
            let mut parents: HashMap<i32, Rc<RefCell<TreeNode>>> = HashMap::new();
            let mut num_to_node: HashMap<i32, Rc<RefCell<TreeNode>>> = HashMap::new();
            Self::dfs(rt.clone(), &mut parents, &mut num_to_node);
            let mut queue: VecDeque<Rc<RefCell<TreeNode>>> = {
                let mut queue: VecDeque<Rc<RefCell<TreeNode>>> = VecDeque::new();
                if let Some(n) = num_to_node.get(&start) {
                    queue.push_back(n.clone());
                }
                queue
            };
            let mut mins: i32 = 0;
            let mut seen: HashSet<i32> = {
                let mut seen = HashSet::new();
                seen.insert(start);
                seen
            };
            while !queue.is_empty() {
                let len_q: usize = queue.len();
                for _ in 0..len_q {
                    if let Some(cur) = queue.pop_front() {
                        let val: i32 = cur.borrow().val;
                        if let Some(n) = parents.get(&val) {
                            if seen.insert(n.borrow().val) {
                                queue.push_back(n.clone());
                            }
                        }
                        if let Some(l) = cur.borrow().left.clone() {
                            if seen.insert(l.borrow().val) {
                                queue.push_back(l);
                            }
                        }
                        if let Some(r) = cur.borrow().right.clone() {
                            if seen.insert(r.borrow().val) {
                                queue.push_back(r);
                            }
                        }
                    }
                }
                mins += 1;
            }
            // to turn into 0-indexed
            return mins - 1;
        } else {
            return 0;
        }
    }
    fn dfs(
        node: Rc<RefCell<TreeNode>>,
        parents: &mut HashMap<i32, Rc<RefCell<TreeNode>>>,
        num_to_node: &mut HashMap<i32, Rc<RefCell<TreeNode>>>,
    ) {
        let val = node.borrow().val;
        num_to_node.insert(val, node.clone());
        if let Some(l) = node.borrow().left.clone() {
            let l_val: i32 = l.borrow().val;
            parents.insert(l_val, node.clone());
            Self::dfs(l, parents, num_to_node);
        }
        if let Some(r) = node.borrow().right.clone() {
            let r_val: i32 = r.borrow().val;
            parents.insert(r_val, node.clone());
            Self::dfs(r, parents, num_to_node);
        }
    }
}