// Runtime: 29 ms (Top 100.0%) | Memory: 6.22 MB (Top 30.7%)

impl Solution {
    pub fn k_smallest_pairs(nums1: Vec<i32>, nums2: Vec<i32>, k: i32) -> Vec<Vec<i32>> {
        use std::collections::BinaryHeap;
        use std::cmp::Reverse;

        let mut heap: BinaryHeap<(Reverse<i32>, usize, usize)> = (0..nums1.len()).map(|i| (Reverse(nums1[i] + nums2[0]), i, 0)).collect();
        let mut ret = Vec::with_capacity(k as usize);

        while let Some((_, i, j)) = heap.pop() {
            ret.push(vec![nums1[i], nums2[j]]);
            if ret.len() == k as usize {
                break;
            }

            if j + 1 < nums2.len() {
                heap.push((Reverse(nums1[i] + nums2[j + 1]), i, j + 1));
            }
        }
        ret
    }
}