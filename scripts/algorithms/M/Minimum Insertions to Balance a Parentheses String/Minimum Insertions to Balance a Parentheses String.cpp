// Runtime: 34 ms (Top 32.51%) | Memory: 13.40 MB (Top 25.91%)

class Solution {
public:
    int minInsertions(string s) {
        stack<char> v;
        int ans = 0;
        for(int i = 0;i < s.size();i++){
            if(s[i] == '(') v.push(s[i]);
            else{
                if(s[i] == ')' && i < s.size() && s[i + 1] == ')') {
                    if(!v.empty())
                        v.pop();
                    else ans++;
                    i++;       // because we considered i+1 in this case
                }
                else if(s[i] == ')' && i < s.size() && s[i + 1] != ')'){
                    if(!v.empty()){
                        v.pop();
                        ans++;
                    }
                    else ans += 2;
                }
            }
        }
        if(v.empty()) return ans;
        return v.size()*2 + ans;
    }
};
