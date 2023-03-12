class Solution {
public:
    int countHomogenous(string s) {
        int mod=1e9+7,size=s.size(),i=0,j=0,count=0;
        while(j<size){
            if(s[j]!=s[j+1]){
                long n=j-i+1;
                count = count + (n*(n+1)/2)%mod;
                i=j+1;
            }
            j++;
        }
        return count;
    }
};