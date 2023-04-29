class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(s[i]==')')
            {
              int strt=st.top();
              strt=strt+1;
              int end=i;
              reverse(s.begin()+strt,s.begin()+end);
              st.pop();
            }
        }
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' || s[i]==')')
            {
                continue;
            }
            ans+=s[i];
        }
        return ans;
    }
};