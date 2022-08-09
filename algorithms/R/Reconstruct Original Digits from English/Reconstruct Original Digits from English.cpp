class Solution {
public:
    
    vector<string> digits{"zero","one","two","three","four","five","six","seven","eight","nine"};
    void fun(int x,string &ans,vector<int> &m){
        for(int i = x;i<=9;i+=2){
            string t = digits[i];
            if(t.length() == 3){
                if(m[t[0]-'a'] > 0 && m[t[1]-'a'] > 0 && m[t[2]-'a'] > 0){
                    int min_o = min({m[t[0]-'a'] ,m[t[1]-'a'] , m[t[2]-'a']});
                    m[t[0]-'a'] -= min_o;
                    m[t[1]-'a'] -= min_o;
                    m[t[2]-'a'] -= min_o;
                    while(min_o--) ans += (char)(i +'0');
                }
            }else if(t.length() == 4){
                if(m[t[0]-'a'] > 0 && m[t[1]-'a'] > 0 && m[t[2]-'a'] > 0 && m[t[3]-'a'] > 0){
                    int min_o = min({m[t[0]-'a'] ,m[t[1]-'a'] , m[t[2]-'a'], m[t[3]-'a']});
                    m[t[0]-'a'] -= min_o;
                    m[t[1]-'a'] -= min_o;
                    m[t[2]-'a'] -= min_o;
                    m[t[3]-'a'] -= min_o;
                    while(min_o--) ans += (char)(i +'0');
                }
            }else if(t.length() == 5){
                if(m[t[0]-'a'] > 0 && m[t[1]-'a'] > 0 && m[t[2]-'a'] > 0 && m[t[3]-'a'] > 0 && m[t[4]-'a'] > 0){
                    int min_o = min({m[t[0]-'a'] ,m[t[1]-'a'] , m[t[2]-'a'], m[t[3]-'a'], m[t[4]-'a']});
                    m[t[0]-'a'] -= min_o;
                    m[t[1]-'a'] -= min_o;
                    m[t[2]-'a'] -= min_o;
                    m[t[3]-'a'] -= min_o;
                    m[t[4]-'a'] -= min_o;
                    while(min_o--) ans += (char)(i +'0');
                }
            }
        }
    }
    
    string originalDigits(string s) {
        string ans;
        vector<int> m(26,0);
        for(auto x:s) m[x-'a']++;
        fun(0,ans,m);
        fun(1,ans,m);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
