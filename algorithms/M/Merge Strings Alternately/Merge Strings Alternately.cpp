class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string final="";
        int p=word1.size();
        int q=word2.size();
        int n=max(p,q);
        for(int i=0;i<n;i++){
            if(p){
                final=final+word1[i];
                p--;
            }
            if(q){
                final=final+word2[i];
                q--;
            }
        }
        return final;
    }
};
