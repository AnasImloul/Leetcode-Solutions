// Runtime: 345 ms (Top 11.27%) | Memory: 21.5 MB (Top 63.27%)
class Solution {
public:

    int helper(string&str, char a, char b){
        int count =0;
        stack<char> st;
        for(int i=0;i<str.length();i++) {
            if(!st.empty() && str[i]==b && st.top()==a) {
                st.pop();
                count++;
            }
            else {
                st.push(str[i]);
            }
        }
        str="";
        while(!st.empty()) {
            str += st.top();
              st.pop();
            }
        reverse(str.begin(),str.end());
        return count;
    }

    int maximumGain(string s, int x, int y) {
        int ca=0,cb=0;
        if(x>y) {
            ca = helper(s,'a','b');
            cb = helper(s,'b','a');
        }
        else {
            cb = helper(s,'b','a');
            ca = helper(s,'a','b');
        }
        return ca*x + cb*y;
    }
};