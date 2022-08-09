class Solution {
public:
    int i = 0;
    
    int calculate(string s) {
        vector<int> stk;
        char sign = '+';
        int num = 0;
        while(i < s.size()){
            char ch = s[i++];   
            if(isdigit(ch)){
                num = num * 10 + (ch - '0');
            }
            if(ch == '(')  num = calculate(s);
            if(i >= s.size() || ch == '+' || ch == '-' || ch == ')'){
                if(sign == '+')  stk.push_back(num);
                else stk.push_back(-num);
                sign = ch;
                num = 0;
            }
            if(ch == ')')  break;
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};
