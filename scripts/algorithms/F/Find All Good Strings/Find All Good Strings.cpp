// Runtime: 38 ms (Top 52.14%) | Memory: 6.9 MB (Top 75.00%)
class Solution {
private:
    string s1,s2,evil;
    vector<int> KMP;
    int dp[500][50][2][2]={};
    int calculate(int pos,int evilpos,bool s1equal, bool s2equal){
        if(pos==s1.size())
            return 1;
        if(!dp[pos][evilpos][s1equal][s2equal]){
            for(auto c='a'; c<='z';c++){
                int curpos=evilpos;
                while(c!=evil[curpos] && curpos>0)
                    curpos=KMP[curpos-1];
                if(c==evil[curpos]) curpos++;
                if((s1equal && c<s1[pos]) || (s2equal && c>s2[pos]) || (curpos==evil.size()))
                    continue;
                else
                {
                    dp[pos][evilpos][s1equal][s2equal]=(dp[pos][evilpos][s1equal][s2equal]+calculate(pos+1,curpos,(s1equal && c==s1[pos]),s2equal && c==s2[pos])) % 1000000007;
                }
            }
        }
        return dp[pos][evilpos][s1equal][s2equal];
    }
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        this->s1=s1;
        this->s2=s2;
        this->evil=evil;
        KMP.resize(evil.size(),0);
        //build kmp of evil word
        KMP[0]=0;
        int k=0;
        for(int i=1;i<evil.length();i++){
            while(evil[i]!=evil[k] && k>0) k=KMP[k-1];
            if(evil[i]==evil[k]) KMP[i]=++k;
        }
        return calculate(0,0,1,1);
     }

};