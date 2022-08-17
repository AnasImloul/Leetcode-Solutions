class Solution {
public:
    string makeFancyString(string s) {
        int cnt=1;
        string ans="";    ans.push_back(s[0]);
		
        for(int i=1;i<s.length();++i) {
            cnt=s[i]==s[i-1]? cnt+1:1;

            if(cnt<3) {
                ans.push_back(s[i]);
            }
        }
        return ans;

    }
};
};
