class Solution {
public:
    vector<int> zfunction(string s)
    {
        int n = s.size();
        vector<int> z(n,0);
        z[0]=n;
        int l=0,r=0;
        for(int i=1;i<n;++i)
        {
            if(i<=r)
                z[i] = min(r-i+1,z[i-l]);
            while(i+z[i]<n && s[z[i]] == s[i+z[i]])
                ++z[i];
           if(i+z[i]-1 > r)
               l = i, r = i+z[i]-1;
        }
        return z;
    }
    long long sumScores(string s) {
        vector<int> z = zfunction(s);
        long long sum=0;
        sum = accumulate(begin(z),end(z),sum);
        return sum;
    }
};
