// Runtime: 253 ms (Top 86.72%) | Memory: 6.9 MB (Top 96.68%)
class Solution {
public:
    static const int N=2005;
    int mod=1e9+7;
    int B=31;
    long long h[N],p[N],invp[N];
    int modexp(int x,int y){
        int res=1;
        while(y>0){
            if(y&1) res=((long long)res*x)%mod;
            x=((long long)x*x)%mod;
            y=y>>1;
        }
        return res;
    }
    int sub_hash(int l,int r){
        int ans=h[r];
        if(l>0)
            ans=((ans+mod-h[l-1])*invp[l]*1LL)%mod;
        return ans;
    }
    int distinctEchoSubstrings(string text) {
        set<int> res;
        int ans=0;
        p[0]=1;invp[0]=1;
        for(int i=1;i<2005;i++){
            p[i]=(p[i-1]*B)%mod;
        }
        for(int i=1;i<N;i++){
            invp[i]=(invp[i-1]*modexp(B,mod-2))%mod;
        }
        int n=text.size();
        h[0]=(text[0]-'a'+1);
        for(int i=1;i<n;i++){
            h[i]=(h[i-1]+((text[i]-'a'+1)*p[i])*1LL)%mod;
        }
        for(int len=1;len<=n/2;len++){
            for(int i=0;i<n+1-2*len;i++){
                int a=sub_hash(i,i+len-1);
                int b=sub_hash(i+len,i+2*len-1);
                if(a==b){
                    if(res.find(a)==res.end()){
                        res.insert(a);
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};