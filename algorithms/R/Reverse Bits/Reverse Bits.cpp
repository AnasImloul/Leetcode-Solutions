class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans =0;
        int i =1;
        int bit =0;
        while(i<32){
            bit = n&1;
            ans = ans|bit;
            n = n>>1;
            ans = ans<<1;
            i++;
        }
        if (i ==32){
            bit = n&1;
            ans = ans|bit;
        }
        return ans;
    }
};
