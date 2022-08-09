class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        int count=0, inStack=0;
        int n=s.size();
        for(int i=0; i<n; i++) 
            if(s[i]==letter)
                count++;
        string res="";
        int i=0;
        while(i<n) {
            if(res.empty())
                res.push_back(s[i]);
            else {
            while(!res.empty() && res.back()>s[i] && n-i+res.size()>k) {
                if(res.back()==letter && count+inStack-1>=repetition) {
                        res.pop_back();
                        inStack--;
                }
                else if(res.back()==letter)
                    break;
                else
                res.pop_back();
            }
            if(s[i]==letter) {
                inStack++;
                count--;
            }
            res.push_back(s[i]);
            }
            i++;
        }
        string ret="";
        for(int i=0;i<res.size();i++)
        {
            if(res[i]==letter && repetition>0 && k>0)
            {
                repetition--;
                ret+=res[i];
                k--;
            }
            else if(k-repetition>0)
            {
				k--;
				ret+=res[i];   
            }
        }
     return ret;
    }
};
/*
if(find helpful) {
do upvote(); // thanks
}
*/
