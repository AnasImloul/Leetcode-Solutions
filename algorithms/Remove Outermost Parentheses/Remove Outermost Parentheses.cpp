class Solution {
public:
    stack<char>p;
    int count=0;
    string removeOuterParentheses(string s) {
        string ans={};

        for(auto &i:s){
            if(i=='(' && count==0){
                p.push(i);
                count++;
            }
            else if (i=='(' && count!=0){
                ans+='(';
                p.push(i);
                count++;
            }
            else{
                count--;
                p.pop();
                if(count>0) ans+=')';
            }
            
        }
        return ans;
    }
};
