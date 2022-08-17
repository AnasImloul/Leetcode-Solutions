class Solution {
public:
    int getLucky(string s, int k) {
        int n=s.length();
        string ans="";
        for(int i=0;i<n;i++){
            ans+=to_string(int(s[i])-96);
        }
        int temp=0;
        while(k!=0){
            for(int i=0;i<ans.length();i++){
                temp+=(int(ans[i])-'0');
            }
            
            ans=to_string(temp);
            temp=0;
            k--;
        }
        int fans=stoi(ans);
        return fans;
    }
};
