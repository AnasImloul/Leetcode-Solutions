class Solution {
    vector<string>v;
public:
    void solve(string s,int i){
        while(i<s.size() && isdigit(s[i])) i++;
        if(i==s.size()){
            v.push_back(s);
            return;
        }
        solve(s,i+1);
        s[i]=(isupper(s[i]))?s[i]|' ':s[i]&'_';             //using bit manipulation to change into upper or lower case
        solve(s,i+1);
    }
    vector<string> letterCasePermutation(string s) {
        solve(s,0);
        return v;
    }
};