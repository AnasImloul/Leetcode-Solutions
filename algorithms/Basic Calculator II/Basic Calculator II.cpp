class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;
        int n = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] >= '0' && s[i] <= '9'){
                string t(1, s[i]);
                n = n*10 + stoi(t);
            }else if( s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
                nums.push(n);
                n = 0;
                if(!ops.empty() && (ops.top() == '*' || ops.top() == '/') ){
                    int n2 = nums.top(); nums.pop();
                    int n1 = nums.top(); nums.pop();
                    if(ops.top() == '*') nums.push(n1*n2);
                    else nums.push(n1/n2);
                    ops.pop();
                }
                ops.push(s[i]);
            }
        }
        nums.push(n);
        if(!ops.empty() && (ops.top() == '*' || ops.top() == '/') ){
            int n2 = nums.top(); nums.pop();
            int n1 = nums.top(); nums.pop();
            if(ops.top() == '*') nums.push(n1*n2);
            else nums.push(n1/n2);
            ops.pop();
        }
        stack<int> tnums;
        stack<char> tops;
        while(!nums.empty()){ tnums.push(nums.top()); nums.pop();}
        while(!ops.empty()) { tops.push(ops.top()); ops.pop(); }
        
        while(!tops.empty()){ //cout<<tops.top()<<" " ;
            int n1 = tnums.top(); tnums.pop();
            int n2 = tnums.top(); tnums.pop();
            if(tops.top() == '+') tnums.push(n1 + n2);
            else tnums.push(n1 - n2);
            tops.pop();
        }
        return tnums.top();
    }
};
