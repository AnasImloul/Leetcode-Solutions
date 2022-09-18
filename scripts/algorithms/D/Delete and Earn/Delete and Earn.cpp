// Runtime: 44 ms (Top 16.30%) | Memory: 16.4 MB (Top 21.44%)

class Solution {
public:
    // Dynamic Programming : Bottom Up Approach Optmised
    int deleteAndEarn(vector<int>& nums)
    {
        int size = nums.size();

        // Initialise vectors with size 10001 and value 0
        vector<int> memo(10001 , 0);
        vector<int> res(10001 , 0);

        // get the count of elements int res vector
        for(auto num : nums)
            res[num]++;

        // for index : less than 3 calculate memo[i] as the index times number of occurences
        // : greater than equal to 3 as calculate memo[i] as the index times number of occurences + max of the last second and third element
        for(int i = 0 ; i < 10001 ; i++)
            memo[i] += (i < 3) ? (i * res[i]) : (i * res[i]) + max(memo[i-2] , memo[i-3]);

        // return max of last 2 elements
        return max(memo[10000] , memo[9999]);
    }
};