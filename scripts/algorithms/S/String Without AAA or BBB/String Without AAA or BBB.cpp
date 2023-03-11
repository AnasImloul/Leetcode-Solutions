class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans="";
        while(a and b){
            if(a > b) ans += "aab", a--;
            else if(b > a) ans +="bba", b--;
            else ans += "ab";
            a--, b--;
        }
        while(a) ans +='a' , a--;
        while(b) ans +='b' , b--;
        return ans;
    }
};