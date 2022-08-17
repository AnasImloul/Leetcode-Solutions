class Encrypter {
public:
    unordered_set<string> dict;
    unordered_map<char,string> en;
    unordered_map<string,vector<char>> dy;
   
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for(auto& t:dictionary)
         {   dict.insert(t);}
        for(int i=0;i<keys.size();i++)
        {
            char c=keys[i];
            string s=values[i];
            en[c]=s;
            dy[s].push_back(c);
        }
        
    }
    
    string encrypt(string word1) {
        string ans="";
        for(char c:word1)
        {
            ans+=en[c];
        }
        return ans;
    }
    
    int decrypt(string word2) {
        int cnt=0;
        for(auto t:dict)
        {
            string ans="";
            for(int i=0;i<t.size();i++)
            {
                ans+=en[t[i]];
            }
            if(ans==word2)
                cnt++;
        }
        return cnt;
    }
 
};

