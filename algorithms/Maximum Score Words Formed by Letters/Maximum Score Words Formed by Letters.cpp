class Solution {
public:
    int solve(vector<string>& words,vector<int> &f,unordered_map<string,vector<int>> &word_f,
              unordered_map<string,int> &word_score,int n)
    {
        if(n==0)return 0;
        
        vector<int> v=word_f[words[n-1]],temp=f;
        int score=word_score[words[n-1]];
        int flag=1;
        for(int i=0;i<26;i++)
        {
            if(f[i]<v[i])
            {
                flag=0;
                break;
            }
            else
            {
                temp[i]-=v[i];
            }
        }
        if(flag)
        {
            return max(solve(words,f,word_f,word_score,n-1),
                       solve(words,temp,word_f,word_score,n-1)+score);
        }
        else
            return solve(words,f,word_f,word_score,n-1);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> f(26,0);
        for(auto i:letters)f[i-'a']++;
        unordered_map<string,vector<int>> word_f;
        unordered_map<string,int> word_score;
        for(auto s:words)
        {
            vector<int> freq(26,0);
            int total=0;
            for(auto i:s)
            {
                freq[i-'a']++;
                total+=score[i-'a'];
            }
            word_score[s]=total;
            word_f[s]=freq;
        }
        return solve(words,f,word_f,word_score,words.size());
    }
};