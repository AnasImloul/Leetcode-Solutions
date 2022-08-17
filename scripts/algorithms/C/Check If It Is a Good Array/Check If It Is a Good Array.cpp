class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int gcd=0;
        for(int i=0; i<nums.size(); i++){
            gcd=__gcd(gcd,nums[i]);
        }return gcd==1;
    }
};
