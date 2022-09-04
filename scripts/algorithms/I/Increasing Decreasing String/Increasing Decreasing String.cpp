// Runtime: 10 ms (Top 67.59%) | Memory: 7.5 MB (Top 80.20%)
class Solution {
public:
    string sortString(string s) {
       int count [26]={0};
        for(int i =0 ;i< s.size();i++){
            char ch = s[i];
            count[ch-'a']++;
        }
        string res ;
        while(res.size()!=s.size()){
            for(int i = 0 ;i<26;i++){
                if(count[i] >0) {
                     char ch = i+'a';
                      res += ch;
                      count[i]--;
                }
           }
            for(int i = 25 ;i>=0 ;i--){
                if(count[i] >0){
                     char ch= i+'a';
                     res += ch;
                     count[i]--;
                    }
              }
         }
        return res ;
    }
};