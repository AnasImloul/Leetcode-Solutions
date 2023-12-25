// Runtime: 6 ms (Top 43.33%) | Memory: 7.90 MB (Top 47.14%)

class Solution {
public:
    int longestDecomposition(string text) {
        int ans=0,i=0,j=text.size()-1;
        string s="",t="";
        
        while(i<j){
            s+=text[i];
            t+=text[j];
            string rev=t;
            reverse(rev.begin(),rev.end());
            
            if(s==rev){
                ans++;
                t="";
                s="";
            }
            
            i++;
            j--;
        }
        ans*=2;
        
        if(i==j || s.size()!=0)ans++;
        return ans;
    }
};