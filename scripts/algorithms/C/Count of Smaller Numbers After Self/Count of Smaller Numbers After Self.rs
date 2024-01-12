// Runtime: 80 ms (Top 62.5%) | Memory: 6.70 MB (Top 12.5%)

fn merge_sort(nums: &mut Vec<(usize, i32)>, l: usize, r: usize, ans: &mut Vec<i32>) {
    if l < r - 1 {
        let m = l + (r - l) / 2;
        merge_sort(nums, l, m, ans);
        merge_sort(nums, m, r, ans);
        merge(nums, l, m, r, ans);
    }
}

fn merge(nums: &mut Vec<(usize, i32)>, l: usize, m: usize, r: usize, ans: &mut Vec<i32>) {
    let mut arr = Vec::with_capacity(r - l);
    let mut i  = l;
    let mut j = m;
    let mut ct = 0;
    while i < m && j < r {
        if nums[i].1 <= nums[j].1 {
            ans[nums[i].0] += ct;
            arr.push(nums[i]);
            i += 1;
        } else {
            ct += 1;
            arr.push(nums[j]);
            j += 1;
        }
    }
    while i < m {
        ans[nums[i].0] += (r - m) as i32;
        arr.push(nums[i]);
        i += 1;
    }
    while j < r {
        arr.push(nums[j]);
        j += 1;
    }

    for (i, n) in arr.into_iter().enumerate() {
        nums[l + i] = n;
    }
}

impl Solution {
    pub fn count_smaller(nums: Vec<i32>) -> Vec<i32> {
        let len = nums.len();
        let mut ans = vec![0; len];
        let mut nums = nums.into_iter().enumerate().collect();
        merge_sort(&mut nums, 0, len, &mut ans);
        ans
    }
}
