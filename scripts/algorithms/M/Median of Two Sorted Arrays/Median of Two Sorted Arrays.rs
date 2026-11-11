// Runtime: 0 ms (Top 100.00%) | Memory: 2.30 MB (Top 22.15%)

impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let mut merged: Vec<i32> = Vec::new();
        let (mut i, mut j) = (0, 0);

        while i < nums1.len() && j < nums2.len() {
            if nums1[i] < nums2[j] {
                merged.push(nums1[i]);
                i += 1;
            } else {
                merged.push(nums2[j]);
                j += 1;
            }
        }

        while i < nums1.len() {
            merged.push(nums1[i]);
            i += 1;
        }
        while j < nums2.len() {
            merged.push(nums2[j]);
            j += 1;
        }

        let mid = merged.len() / 2;
        if merged.len() % 2 == 0 {
            return (merged[mid-1] + merged[mid]) as f64 / 2.0;
        } else {
            return merged[mid] as f64;
        }
    }
}
