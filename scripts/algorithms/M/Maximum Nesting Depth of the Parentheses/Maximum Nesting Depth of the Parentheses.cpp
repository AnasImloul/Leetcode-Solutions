// Runtime: 0 ms (Top 100.00%) | Memory: 6.3 MB (Top 56.85%)
class Solution {
public:
    int maxDepth(string s) {
        int maxi=0,curr=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                maxi=max(maxi,++curr);
            }else if(s[i]==')'){
                curr--;
            }
        }
        return maxi;
    }
};