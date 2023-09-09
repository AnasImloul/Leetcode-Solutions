// Runtime: 435 ms (Top 33.3%) | Memory: 2.11 MB (Top 66.6%)

use std::cell::*;
use std::char::*;
use std::cmp::*;
use std::collections::hash_map::*;
use std::collections::*;
use std::iter::*;
use std::mem::*;
use std::ops::*;
use std::*;

fn dfs(pos: usize, arr: &Vec<i32>, d: usize, count: &mut Vec<i32>) -> i32 {
    // check if we can jump
    let mut can_jump_left = true;
    let mut can_jump_right = true;
    if pos == 0 || arr[pos - 1] >= arr[pos] {
        can_jump_left = false;
    }
    if pos == arr.len() - 1 || arr[pos + 1] >= arr[pos] {
        can_jump_right = false;
    }

    let mut ret = 0;

    if can_jump_left {
        for i in 1..min(pos, d) + 1 {
            let i = pos - i;
            if arr[i] >= arr[pos] {
                break;
            }

            if count[i] == -1 {
                let m = dfs(i, arr, d, count);
                ret = max(ret, m + 1);
            } else {
                ret = max(ret, count[i] + 1);
            }
        }
    }

    if can_jump_right {
        for i in 1..min(arr.len() - pos - 1, d) + 1 {
            let i = pos + i;
            if arr[i] >= arr[pos] {
                break;
            }

            if count[i] == -1 {
                let m = dfs(i, arr, d, count);
                ret = max(ret, m + 1);
            } else {
                ret = max(ret, count[i] + 1);
            }
        }
    }

    count[pos] = ret;
    ret
}

impl Solution {
    pub fn max_jumps(arr: Vec<i32>, d: i32) -> i32 {
        let mut ans = 0;
        let mut count = vec![-1; arr.len()];

        for i in 0..arr.len() {
            count.fill(-1);
            ans = max(ans, dfs(i, &arr, d as usize, &mut count));
        }

        ans + 1
    }
}