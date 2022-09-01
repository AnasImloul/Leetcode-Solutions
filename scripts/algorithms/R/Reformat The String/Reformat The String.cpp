// Runtime: 7 ms (Top 65.55%) | Memory: 7.5 MB (Top 65.85%)
class Solution {
public:
    string reformat(string s) {
        string dg,al;
        for(auto&i:s)isdigit(i)?dg+=i:al+=i;
        if(abs((int)size(dg)-(int)size(al))>1) return "";
        int i=0,j=0,k=0;
        string ans(size(s),' ');
        bool cdg=size(dg)>size(al);
        while(k<size(s)){
            if(cdg)ans[k++]=dg[i++];
            else ans[k++]=al[j++];
            cdg=!cdg;
        }
        return ans;
    }
};