class Solution {
public:
    string getSmallestString(int n, int k) {
        string str="";
        for(int i=0;i<n;i++){
            str+='a';
        }
        int curr=n;
        int diff=k-curr;
        if(diff==0) return str;
        for(int i=n-1;i>=0 && diff>0;i--){
            if(diff>25){
                str[i]='z';
                diff-=25;
            }else{
                str[i]=char('a'+diff);
                return str;
            }
        }
        return str;
    }
};
// a a a a a
// 5
// diff= 73-5
// 
