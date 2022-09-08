// Runtime: 85 ms (Top 5.41%) | Memory: 22.2 MB (Top 5.04%)
class Solution {
public:
    bool check(stack<char> st, string part){
        int n2 = part.length();
        int j = n2-1;
        while( j >=0 and st.top() == part[j]){
            st.pop();
            j--;
        }
        return (j == -1);
    }
    string removeOccurrences(string s, string part) {
        int n1 = s.length() , n2 = part.length();
        stack<char>st;
        string str = "" ;
        for(int i=0;i<n1;++i){
            st.push(s[i]);
            if(st.size() >= n2){
                if(check(st,part)){
                    int ct = n2;
                    while(ct--){
                        st.pop();
                    }
                }
            }
        }
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};