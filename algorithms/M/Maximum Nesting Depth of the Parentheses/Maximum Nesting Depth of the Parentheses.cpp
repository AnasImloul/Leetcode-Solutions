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
