// Runtime: 3 ms (Top 40.43%) | Memory: 6.60 MB (Top 24.35%)

class Solution {
public:
    string digitSum(string s, int k) {
        
        if(s.length()<=k)
            return s;
        
        string ans="";
        int sum=0,temp=k;
        int len = s.length();
        for(int i=0;i<len;i++){
            sum += (s[i] -'0');
            temp--;
            if(temp==0){
                ans+= to_string(sum);
                temp=k;
                sum=0;
            }
        }
        if(temp!=k){
        ans+= to_string(sum);
        }
        if(ans.length()>k)
            ans = digitSum(ans,k);
        return ans;
    }
};
