// Runtime: 357 ms (Top 8.7%) | Memory: 1.99 MB (Top 95.6%)

impl Solution {
    pub fn find_target_sum_ways(nums: Vec<i32>, target: i32) -> i32 {
        let mut count = 0;
        Self::dfs(&nums, target,0, 0,&mut count);
        count
    }
    fn dfs(nums: &Vec<i32>, target:i32, current_sum:i32, current_length: usize, res: &mut i32){
        if current_length==nums.len(){
            if current_sum==target{
                *res+=1;
            }
            return;
        }
        let curr_num = nums[current_length];
        Self::dfs(nums,target,current_sum+curr_num,current_length+1,res);
        Self::dfs(nums,target,current_sum-curr_num,current_length+1,res);
    }
}