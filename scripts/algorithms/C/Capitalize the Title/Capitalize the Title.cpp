class Solution {
public:
    string capitalize(string s){
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        if(s.length() <= 2){
            return s;
        }
        s[0] = s[0] - 'a' + 'A';
        return s;
    }
    string capitalizeTitle(string title) {
        string str = "";
        string ans = "";
        for(int i = 0; i < title.length(); i++){
            if(title[i] != ' '){
                str.push_back(title[i]);
            }
            else{
                str = capitalize(str);
                ans += str + " ";
                str = "";
            }
        }
        str = capitalize(str);
        ans += str;
        return ans;
    }
};