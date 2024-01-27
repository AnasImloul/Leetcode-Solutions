// Runtime: 12 ms (Top 100.0%) | Memory: 4.00 MB (Top 100.0%)

impl Solution 
{
    pub fn longest_subarray(nums: Vec<i32>) -> i32 
    {
        // [1] the answer to the problem is the length of 
        //     the longest subarray with all elemets equal 
        //     to the maximum value of 'nums'
        let max_num     = *nums.iter().max().unwrap();
        
        let mut max_len = 0;
        let mut cur_len = 0;
                
        // [2] iterate and update the maximum length
        for n in nums.into_iter()
        {           
            if n == max_num { cur_len += 1; }
            else            { max_len = max_len.max(cur_len); cur_len = 0; }
        }
        
        max_len.max(cur_len)
    }
}
