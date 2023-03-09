class Solution {
public:
    int mod=1e9+7;
    int Value(vector<int> a, int n){
        vector<long long>pre(n+2,0);
        for(int i=1;i<=n;i++)
            pre[i]=(pre[i-1]+a[i-1])%mod;
        for(int i=1;i<=n+1;i++)
            pre[i]=(pre[i-1]+pre[i])%mod;
        for(int i=n+1;i>0;i--)
            pre[i]=pre[i-1];

        vector<int> l(n,-1),r(n,n);
        stack<int> st;
        // Find all left index
        for(int i = 0; i < n; i++){
            while (!st.empty() && a[st.top()] >= a[i])
                st.pop();
            if (!st.empty())
                l[i] = st.top();

            st.push(i);
        }

        while(!st.empty())
        st.pop();

        // Find all right index
        for(int i = n - 1; i >= 0; i--){
            while (!st.empty() && a[st.top()] > a[i])
                st.pop();

                if (!st.empty())
                    r[i] = st.top();

            st.push(i);
        }
        // for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<"\n";
        // for(int i=0;i<n;i++) cout<<l[i]<<" "; cout<<"\n";
        // for(int i=0;i<n;i++) cout<<r[i]<<" "; cout<<"\n";
        
        long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (((pre[r[i] + 1] - pre[i + 1]) * (i - l[i]) % mod + mod * 2 - 
               (pre[i + 1] - pre[l[i] + 1]) * (r[i] - i) % mod) % mod * a[i]) % mod;
        ans %= mod;
    }
    return (int) ans;

    }
    int totalStrength(vector<int>& s) {
        int n=s.size();
        return Value(s,n);
    }
};