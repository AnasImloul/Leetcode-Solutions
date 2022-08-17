class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string n="";
        for(string str:words){
            for(char ch:str){
                n+=ch;
            }
            if(n==s){
                return true;
            }
        }
        
        return false;
    }
};
