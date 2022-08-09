class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1)
            return true;
        long long p=1;
        for(int i=1;i<n;i++)
        {
            p=p*4;
            if(p==n)
                return true;
            if(p>n)
                return false;
        }
        return false;
    }
};
