class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        stack<char>st;
        string ans="";
        for(int i=0;i<s.length();i++){
            if(isalpha(s[i]) || isdigit(s[i])){
                st.push(s[i]);
            }
        }
        int i=0;
        while(st.size()>0){
            char ch=st.top();
            st.pop();
            if(isalpha(ch)) 
            {
                ch=toupper(ch);
            }
            ans+=ch;
            if((i+1)%k==0 && st.size()!=0) ans+='-';
            i++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};