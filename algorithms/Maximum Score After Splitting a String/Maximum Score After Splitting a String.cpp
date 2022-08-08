class Solution {
public:
    int maxScore(string s) {
        vector<int>z(size(s)),o(size(s));
        z[0]=s[0]=='0';
        o[size(s)-1]=s[size(s)-1]=='1';
        int ans=0;
        for(int i=1,j=size(s)-2;i<s.size();++i,--j){
            z[i]=z[i-1];
            o[j]=o[j+1];
            if(s[i]=='0')++z[i];
            if(s[j]=='1')++o[j];
        }
        for(int i=0;i<s.size()-1;++i) ans=max(ans,z[i]+o[i+1]);
        return ans;
    }
};

class Solution {
public:
    int maxScore(string s) {
        int o=0,z=0,ans=0;
        for(auto&i:s)o+=i=='1';
        for(int i=0;i<size(s)-1;++i){
            s[i]=='0'?++z:--o;
            ans=max(ans,o+z);
        }
        return ans;
    }
};
