// Runtime: 12 ms (Top 82.80%) | Memory: 8.8 MB (Top 30.73%)
class Solution {
    /*
    To calculate the substring the formula is (n*n+1)/2 so just find the range and calculate the substrings.
    */
int mod=1e9+7;
    long calculateNumbeOfSubstrings(string &s,int &l,int &r){
        long range=r-l;
        long ans=range*(range+1)/2;
        return ans;
    }
public:
    int numSub(string s) {
        int ans=0;
        int len=s.size();
        int r=0,l=0;
        while(r<len){
            while(r<len && s[l]!='1'){
                l++;
                r++;
            }
            while(r<len && s[r]!='0'){
                r++;
            }
               ans=(ans+calculateNumbeOfSubstrings(s,l,r))%mod;
                l=r;
        }
        return ans;
    }
};
