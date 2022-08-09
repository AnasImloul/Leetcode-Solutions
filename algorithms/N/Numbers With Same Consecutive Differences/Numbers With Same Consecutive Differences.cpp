class Solution {
public:
    vector<int> res;
    void solve(int num,int n,int k)
    {
        if(n==1)
        {
            res.push_back(num);
            return;
        }
        int dig=num%10;
        if(dig+k<=9 && k!=0)
        {
            solve(num*10+dig+k,n-1,k);
        }
        if(dig-k>=0)
        {
            solve(num*10+dig-k,n-1,k);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        res.clear();
        for(int i=1;i<=9;++i)
        {
            solve(i,n,k);
        }
        return res;
    }
};
