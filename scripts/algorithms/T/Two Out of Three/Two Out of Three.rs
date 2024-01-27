// Runtime: 2 ms (Top 50.0%) | Memory: 2.10 MB (Top 66.67%)

impl Solution {
    pub fn two_out_of_three(nums1: Vec<i32>, nums2: Vec<i32>, nums3: Vec<i32>) -> Vec<i32> {
        let mut counter = [0_i32; 101];
        nums1.iter().for_each(|&x| counter[x as usize] |= 0b001);
        nums2.iter().for_each(|&x| counter[x as usize] |= 0b010);
        nums3.iter().for_each(|&x| counter[x as usize] |= 0b100);
        counter
            .iter()
            .cloned()
            .enumerate()
            .filter_map(|(ind, x)| match x.count_ones() >= 2 {
                true => Some(ind as i32),
                false => None,
            })
            .collect::<Vec<_>>()
    }
}
