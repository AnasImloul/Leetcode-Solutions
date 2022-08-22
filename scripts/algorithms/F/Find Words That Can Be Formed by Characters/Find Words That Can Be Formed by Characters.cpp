// Runtime: 99 ms (Top 61.59%) | Memory: 17.8 MB (Top 75.26%)
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> dp(26,0);
        vector<int> dp2(26,0);
        for(int i=0;i<chars.size();i++){
            dp[chars[i]-'a']++;
        }
        dp2 = dp;
        bool flg = false;
        int cnt=0;
        for(int i=0;i<words.size();i++){
            string a = words[i];
            for(int j=0;j<a.size();j++){
                if(dp[a[j]-'a']>0){
                    dp[a[j]-'a']--;
                }
                else{
                    flg = true;
                    dp = dp2;
                    break;
                }
            }
            if(!flg){
               cnt += a.size();
            }
            dp = dp2;
            flg = false;
        }
        return cnt;
    }
};