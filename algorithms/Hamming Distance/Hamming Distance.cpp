class Solution {
public:
    int hammingDistance(int x, int y) {
        int val = (x^y);
        int ans = 0;
        for(int i = 31; i >= 0; --i){
            if(val & (1 << i)) ans++;
        }
        return ans;
    }
};
