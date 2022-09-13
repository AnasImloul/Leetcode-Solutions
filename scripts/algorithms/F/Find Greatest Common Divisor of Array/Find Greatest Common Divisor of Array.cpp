// Runtime: 20 ms (Top 7.45%) | Memory: 12.5 MB (Top 65.76%)
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = nums[0], mx = nums[0];
        for(auto n: nums)
        {
            // finding maximum, minimum values of the array.
            if(n > mx) mx = n;
            if(n < mn) mn = n;
        }

        for(int i = mn; i >= 1; i--)
        {
            // finding greatest common divisor (GCD) of max, min.
            if((mn % i == 0) && (mx % i == 0)) return i;
        }
        return 1;
    }
};