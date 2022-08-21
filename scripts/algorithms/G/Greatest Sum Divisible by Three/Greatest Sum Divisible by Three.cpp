// Runtime: 44 ms (Top 95.18%) | Memory: 25.1 MB (Top 80.72%)

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> twos = {(int)1e4+1, (int)1e4+1}, ones = {(int)1e4+1, (int)1e4+1};
        int res = 0;
        for(int i: nums) {
            if(i%3 == 2) {
                if(i <= twos[0]) {
                    twos[1] = twos[0], twos[0] = i;
                }
                else if(i < twos[1]) twos[1] = i;
            }
            else if(i%3 == 1) {
                if(i <= ones[0]) {
                    ones[1] = ones[0], ones[0] = i;
                }
                else if(i < ones[1]) ones[1] = i;
            }
            res += i;
        }
        if(res%3 == 2)
            return max(res - twos[0], res - ones[0] - ones[1]);
        else if(res%3 == 1)
            return max(res - ones[0], res - twos[0] - twos[1]);
        return res;
    }
};