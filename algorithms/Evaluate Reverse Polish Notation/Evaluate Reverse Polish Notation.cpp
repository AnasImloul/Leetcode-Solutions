class Solution {
public:
    int stoi(string s){
        int n = 0;
        int i = 0;
        bool neg = false;
        if(s[0] == '-'){
            i++;
            neg = true;
        }
        for(; i < s.size(); i++){
            n = n*10 + (s[i]-'0');
        }
        if(neg) n = -n;
        return n;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        int n = tokens.size();
        for(int i = 0; i < n; i++){
            string str = tokens[i];
            if(str == "*"){
                int n1 = s.top();
                s.pop();
                int n2 = s.top();
                s.pop();
                int res = n2*n1;
                s.push(res);
            }
            else if(str == "+") {
                int n1 = s.top();
                s.pop();
                int n2 = s.top();
                s.pop();
                int res = n2+n1;
                s.push(res);
            }
            else if(str == "/"){
                int n1 = s.top();
                s.pop();
                int n2 = s.top();
                s.pop();
                int res = n2/n1;
                s.push(res);
            }
            else if(str == "-"){
                int n1 = s.top();
                s.pop();
                int n2 = s.top();
                s.pop();
                int res = n2-n1;
                s.push(res);
            }
            else{
                int num = stoi(str);
                s.push(num);
            }
        }
        return s.top();
    }
};
