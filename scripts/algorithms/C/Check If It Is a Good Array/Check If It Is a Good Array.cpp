// Runtime: 100 ms (Top 27.69%) | Memory: 29.4 MB (Top 37.30%)
class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int gcd=0;
        for(int i=0; i<nums.size(); i++){
            gcd=__gcd(gcd,nums[i]);
        }return gcd==1;
    }
};