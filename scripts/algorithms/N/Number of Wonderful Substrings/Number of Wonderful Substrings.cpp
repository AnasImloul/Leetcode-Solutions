// Runtime: 1019 ms (Top 30.96%) | Memory: 17.6 MB (Top 38.10%)
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n=word.length();
        int mask=0;
        unordered_map<int,int>m;
        m[0]++;
        long long int ans=0;
        for(int i=0;i<n;i++){
            mask = mask^(1<<(word[i]-'a'));
            int temp=mask;
            int j=0;
            while(j<=9){
               int x=temp^(1<<j);
                ans+=m[x];
                j++;

            }
            ans+=m[mask];
            m[mask]++;
        }

        return ans;

    }
};