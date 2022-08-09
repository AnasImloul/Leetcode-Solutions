class Solution {
public:
    unordered_map<string,string> dp;
    bool special(string s){
        int one=0,zero=0;
        
        for(auto ch:s){
            if(ch=='1') one++;
            else zero++;
            if(one<zero) return 0;
        }
        if(one==zero)
            return 1;
        return 0;
    }
    string fun(string s){
        if(s.length()==1) return s;
        if(dp.count(s)) return dp[s];
        string ans=s;
        string start;
        for(int i=0;i<s.length()-1;i++){
            start.push_back(s[i]);
            string end=s.substr(i+1);
            string comb=end+start;
            if(comb>ans and special(start) and special(end)) ans=comb;
        }
        return dp[s]=ans;
    }
    string makeLargestSpecial(string s) {
        string start;
        string ans=s;
        string ss=s;
        for(int i=0;i<s.length();i++){
            string middle;
            for(int j=i;j<s.length();j++){
                middle.push_back(s[j]);
               string end=s.substr(j+1);
                string comb=start+fun(middle)+end;
                if(comb>ans) ans=comb;
            }
            start.push_back(s[i]);
        }
        if(ss==ans) return ans;
        return(makeLargestSpecial(ans));
    }
};
