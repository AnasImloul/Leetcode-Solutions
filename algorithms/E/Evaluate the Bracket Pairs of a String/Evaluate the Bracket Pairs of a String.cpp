class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans; // resultant string
        int n = s.size();
        if(n < 2) return s; // because () will come in pair so, size should be more than 2
        int sz = knowledge.size();
        unordered_map<string, string> mp; // To reduce Runtime otherwise it will give TLE
        for(int i=0; i<sz; ++i){
            mp.insert({knowledge[i][0], knowledge[i][1]}); // Inserting {key, value} pair
        }
        for(int i=0; i<n; i++){
            
            if(s[i] == '('){  
                string key;
                i++;
                while(s[i] != ')'){ // getting key till we get ')'
                    key += s[i++];
                }
                string value;
                if(mp.find(key) != mp.end()){ // If {key, value} pair is present then replace (key) by it's value
                    value = mp[key];
                    ans += value;
                }
                else {// otherwise replace (key) by ?
                    ans += "?";
                }
            }
            else ans += s[i];
        }
        return ans;
    }
};

**Please do upvote**