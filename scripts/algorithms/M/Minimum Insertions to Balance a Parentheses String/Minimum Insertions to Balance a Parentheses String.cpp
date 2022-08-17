class Solution {
public:
    int minInsertions(string s) {
        stack<int> st;
        int n = s.size();
        int insert = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
            {
                if(st.empty())
                {
                    st.push(2);
                }
                else
                {
                    if(st.top() != 2)
                    {
                        st.pop();
                        insert++;
                    }
                    st.push(2);
                }
            }
            else
            {
                if(st.empty())
                {
                    insert++;
                    st.push(1);
                }
                else
                {
                    int dummy = st.top();
                    st.pop();
                    dummy--;
                    if(dummy)
                        st.push(dummy);
                }
            }
        }
        while(!st.empty())
        {
            insert += st.top();
            st.pop();
        }
        return insert;
    }
};
