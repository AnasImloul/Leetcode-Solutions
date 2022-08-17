class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        string ss;
        int n = expression.size();
        for(int i = 0; i < n; i++){
            if(expression[i] == ','){
                ss += '+';
            }
            else{
                ss += expression[i];
                if((isalpha(expression[i]) || expression[i] == '}') && i+1 < n && (isalpha(expression[i+1]) || expression[i+1] == '{')){
                    ss += '*';
                }
            }
        }
        
        stack<char>stk1;
        vector<string>postfix;
        for(char c:ss){
            if(c == '{'){
                stk1.push(c);
            } else if(c == '}') {
                while(stk1.top() != '{'){
                    postfix.push_back(string(1, stk1.top()));
                    stk1.pop();
                }
                stk1.pop();
            } else if(c == '+'){
                while(!stk1.empty() && (stk1.top() == '+' || stk1.top() == '*')){
                    postfix.push_back(string(1, stk1.top()));
                    stk1.pop();
                }
                stk1.push(c);
            } else if(c == '*'){
                while(!stk1.empty() && stk1.top() == '*'){
                    postfix.push_back(string(1, stk1.top()));
                    stk1.pop();
                }
                stk1.push(c);
            } else {
                postfix.push_back(string(1, c));
            }
        }
        while(!stk1.empty()){
            postfix.push_back(string(1, stk1.top()));
            stk1.pop();
        }
        /*for(string sp:postfix){
            cout << sp << " ";
        }
        cout << endl;*/
        stack<vector<string>>cont;
        for(string s:postfix){
            if(isalpha(s[0])){
                cont.push({s});
            } else {
                vector<string>second = cont.top();
                cont.pop();
                vector<string>first = cont.top();
                cont.pop();
                
                if(s[0] == '+'){
                    for(string sec:second){
                        first.push_back(sec);
                    }
                    cont.push(first);
                } else {
                    vector<string>cartesian;
                    for(string fst:first){
                        for(string sec:second){
                            cartesian.push_back(fst + sec);
                        }
                    }
                    cont.push(cartesian);
                }
            }
        }
        set<string>sstr;
        for(string sc:cont.top()){
            sstr.insert(sc);
        }
        
        vector<string>ret(sstr.begin(), sstr.end());
        return ret;
    }
};```