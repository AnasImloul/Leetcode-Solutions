// Runtime: 346 ms (Top 68.74%) | Memory: 123.3 MB (Top 40.85%)
//Approach-1 (Using sorting O(nlogn))
/*
    If you make sure that
    nums[i-1] < nums[i] > nums[i+1]
    You are good to go.

    So, just sort the input and choose wisely to satisfy above condition.

    Example :
    [6,2,0,9,7]
    sort it : [0, 2, 6, 7, 9]

    result : [0, _, 2, _, 6] - 1st loop (fill alternaltely)
    result : [0, 7, 2, 9, 6] - 2nd loop (fill next larger numbers from nums to result in spaces left)

*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        vector<int> result(n);
        int j = 0;
        int i = 0;
        for(; i < n && j < n; i++, j += 2) //alternately fill so that you leave one space in between for large number
            result[j] = nums[i];

        j = 1;
        for(; i < n && j < n; i++, j += 2) //filter the large number in spaces between that we left above
            result[j] = nums[i];

        return result;
    }
};
