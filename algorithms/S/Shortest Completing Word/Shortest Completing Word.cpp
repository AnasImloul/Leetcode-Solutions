	class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) 
    {
        string ans="";
        vector<int> m(26,0);
        for(auto &lp:licensePlate)
        {
            if(isalpha(lp))
                m[tolower(lp)-'a']++;
        }
        for(auto &word:words)
        {
            vector<int> v=m;
            for(auto &ch:word)
            {
                v[tolower(ch)-'a']--;
            }
            bool flag=true;
            for(int i=0;i<26;i++)
            {
                if(v[i]>0)
                    flag =false;
            }
            if(flag&&(ans==""||ans.size()>word.size()))
                ans=word;
        }
        return ans;
        
    }
};
//if you like the solution plz upvote.