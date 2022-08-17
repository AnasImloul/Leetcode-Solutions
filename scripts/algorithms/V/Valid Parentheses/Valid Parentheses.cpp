class Solution {
public:
// Ref:  balanced parenthesis video from LUV bhaiya YT channel 
unordered_map<char,int>symbols={{'[',-1},{'{',-2},{'(',-3},{']',1},{'}',2},{')',3}};
    stack<char>st;
    bool isValid(string s) {
        for(auto &i:s){
            if(symbols[i]<0){
                st.push(i);
            }
            else{
                if(st.empty()) return false;
                char top=st.top();
                st.pop();
                if(symbols[i]+symbols[top]!=0) return false;
            }
        }
    if(st.empty()) return true;
    return false;
        
    }
};
