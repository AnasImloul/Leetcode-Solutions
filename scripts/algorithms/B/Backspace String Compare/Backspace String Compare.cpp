// Runtime: 0 ms (Top 100.00%) | Memory: 6.4 MB (Top 28.52%)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<int> st1;
        stack<int> st2;
        int len = s.length();
        int len2 = t.length();

        for(int i=0; i<len; i++){
            if(s[i] != '#'){
                st1.push(s[i]);
            }
            else{
                if(!st1.empty()){
                    st1.pop();
                }
            }
        }
        for(int i=0; i<len2; i++){
            if(t[i] != '#'){
                st2.push(t[i]);
            }
            else{
                if(!st2.empty()){
                    st2.pop();
                }
            }
        }

        while(!st1.empty() && !st2.empty()){
            if(st1.top() != st2.top()){
                return false;
            }
            st1.pop();
            st2.pop();
        }
        if(st1.empty() && st2.empty()){
            return true;
        }
        return false;
    }
};