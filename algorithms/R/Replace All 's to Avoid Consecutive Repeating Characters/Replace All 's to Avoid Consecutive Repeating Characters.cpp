class Solution {
    char update_char(char x, char y){
        char c = 'a';
        while(c==x || c==y){
            c++;
        }
        return c;
    }
public:
    string modifyString(string s) {
        int l = s.length();
        char c;
        if(s[0] == '?'){
            c = update_char(s[0],s[1]);
            s[0] = c;
        }
        if(s[l-1] == '?'){
            c = update_char(s[l-2],s[l-1]);
            s[l-1] = c;
        }
        for(int i=1; i<l-1; ++i){
            if(s[i] == '?'){
                c = update_char(s[i-1],s[i+1]);
                s[i] = c;
            }
        }
        return s;
    }
};
