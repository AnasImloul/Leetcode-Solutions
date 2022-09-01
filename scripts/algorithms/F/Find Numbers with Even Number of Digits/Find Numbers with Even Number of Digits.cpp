// Runtime: 11 ms (Top 48.50%) | Memory: 9.9 MB (Top 12.31%)
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;

        for(auto it:nums)
        {
            int amount = 0;
            while(it>0)
            {
                amount++;
                it /= 10;
            }
            if (amount % 2 == 0)
            {
                count++;
            }
        }
        return count;
    }
};