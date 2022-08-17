class Solution {
public:
    int magicalString(int n) {
        string s="122";
        int sz=3;
        int start=2,lastDig=2;
        while(sz<n){
            int cnt=s[start++]-'0';
            int currDig=(lastDig==2)?1:2;
            for(int i=0;i<cnt;i++){
                s.push_back('0'+currDig);
                sz++;
            }
            lastDig=currDig;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                ans++;
            }
        }
        return ans;
    }
};