class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        vector<int> v (26,0);
        for(int i=0;i<words.size();i++){
            vector<int> tmp (26,0);
            for(auto ch: words[i]){
                tmp[ch-'a']++;
            }
            if(i==0){
                for(int i=0;i<26;i++)
                    v[i]=tmp[i];
            }
            else
                for(int i=0;i<26;i++)
                    v[i]=min(v[i],tmp[i]);
        }
        for(int i=0;i<26;i++){
            while(v[i]--){
                string s;
                char c='a'+i;
                s.push_back(c);
                ans.push_back(s);
            }
        }
        return ans;
    }
};
