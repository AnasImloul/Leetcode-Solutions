class Solution {
public:
    string thousandSeparator(int n) {
        string s="";
        int a=0;
        if(n==0)return "0";
       while(n>0){
           s+=char(n%10+48);
           a++;
           n/=10;
           if(a==3&&n!=0)
           {
               a=0;
               s+=".";
           }
       }
        reverse(s.begin(),s.end());
        return s;
    }
};
