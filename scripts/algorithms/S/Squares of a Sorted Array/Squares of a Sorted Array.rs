// Runtime: 6 ms (Top 88.02%) | Memory: 2.30 MB (Top 71.26%)

impl Solution {
    pub fn sorted_squares(nums: Vec<i32>) -> Vec<i32> {
        // The code works without this, but it removes a
        // lot of useless allocations for a base case
        if nums.len() == 1 {
            return vec![i32::pow(nums[0], 2)];
        }
        
        // We'll use this for inserting later
        let mut location = nums.len();
        
        // Pre-allocate so we can start indexing from the end
        let mut output = vec![0; location];
        
        // These are our markers for the 2 ends of the array
        let mut left = 0 as usize;
        let mut right = nums.len() - 1;
        
        // We're only going to compute each value once
        let mut computed_left = i32::pow(nums[left], 2);
        let mut computed_right = i32::pow(nums[right], 2);
        
        while left != right {
            // Every loop we're moving one spot further to the left
            location-=1;
            // Every loop iteration we check which value is larger and
            // put that at the end of the output vector that we pre-allocated
            if computed_left > computed_right {
                output[location] = computed_left;
                left+=1;
                computed_left = i32::pow(nums[left], 2);
            } else {
                output[location] = computed_right;
                right-=1;
                computed_right = i32::pow(nums[right], 2);
            }
        }
        // Could do either one, because at this point they should be the
        // same index / value
        output[0] = computed_right;
        return output;
    }
}
