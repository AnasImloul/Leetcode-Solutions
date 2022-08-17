class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a')
                st.push(s[i]);
            else if(s[i]=='b'){
                if(st.empty() || st.top()!='a')
                return false;
                else
                    st.push(s[i]);
            }
            else if(s[i]=='c'){
                if(st.empty() ||  st.top()!='b')
                    return false;
                else{
                    for(int i=0;i<2;i++)
                        st.pop();
                }
            }
        }
        return st.size()==0;
    }
};
