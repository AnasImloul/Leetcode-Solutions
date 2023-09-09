// Runtime: 3 ms (Top 40.0%) | Memory: 3.08 MB (Top 20.0%)

use std::rc::Rc;
use std::cell::RefCell;
use std::cmp::max;

impl Solution {
    pub fn largest_values(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut res: Vec<i32> = vec![];
        let mut queue = vec![root];
        while !queue.is_empty(){
            let k = queue.len();
            let mut current_max = i32::MIN;
            for _i in 0..k {
                match queue.remove(0) {
                    Some(r)=>{
                        current_max = max(current_max, r.borrow().val);
                        if !r.borrow().left.is_none() {
                            queue.push(r.borrow().left.clone());
                        }
                        if !r.borrow().right.is_none() {
                            queue.push(r.borrow().right.clone());
                        }
                    }
                    None=>return res
                };
            }
            res.push(current_max);
        }
        return res;
    }
}