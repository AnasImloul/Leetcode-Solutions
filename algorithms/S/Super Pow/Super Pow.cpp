class Solution {
public:
    int binaryExp(int a, int b, int M)
    {
        int ans = 1;
        a %= M;
        while(b)
        {
            if(b&1) ans = (ans * a)%M;
            a = (a*a)%M, b = b>>1;
        }
        return ans;
    }
    
    int superPow(int a, vector<int>& b) {
        int bmod = 0;
        for(auto it : b)
        {
            bmod = (bmod * 10 + it)%1140;
        }
        
        return binaryExp(a, bmod, 1337);
    }
};
