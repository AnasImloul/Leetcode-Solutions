// Runtime: 2599 ms (Top 5.05%) | Memory: 326.4 MB (Top 5.74%)
class Solution {
public:
    string Reverse(string s){
        for(int i=0;i<s.length()/2;i++){
            swap(s[i],s[s.length()-1-i]);
        }
        return s;
    }

    string invert(string s){
        for(int i=0;i<s.length();i++){
            if(s[i]=='1') s[i]='0';
            else s[i]='1';
        }
        return s;
    }

    string S(int n) {
        if(n==1){
            return "0";
        }
        return S(n-1) + "1" + Reverse(invert(S(n-1)));
    }

    char findKthBit(int n, int k) {
        if(n==1) return '0';
        string s = S(n-1) + "1" + Reverse(invert(S(n-1)));
        return s[k-1];
    }
};