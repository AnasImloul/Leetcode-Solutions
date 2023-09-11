// Runtime: 0 ms (Top 100.0%) | Memory: 2.03 MB (Top 100.0%)

impl Solution 
{
    pub fn seconds_to_remove_occurrences(s: String) -> i32 
    {
        s.chars()
        // [1] leading '1's are irrelevant 
            .skip_while(|&c| c == '1')
        // [2] while iterating, we keep track of zeros and compute swaps
            .fold(
                (0,0), |(swaps, zeros), c|
        // [3] when we encounter '1', we conclude that the amount 
        //     of swaps it requires to travel to left is not less than:
        //     - the amount of zeros seen before
        //     - the amount of swaps needed for previous '1's plus one (if blocked)
                match c 
                {
                    '1' => ((swaps + 1).max(zeros), zeros),
                    '0' => (swaps, zeros + 1),
                    _   => unreachable!("Wrong symbol {}", c)
                }
            ).0 as i32
    }
}