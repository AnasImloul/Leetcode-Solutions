// Runtime: 53 ms (Top 8.77%) | Memory: 56.1 MB (Top 8.93%)
class Solution {
public:
    string ans="";
    int carry=0;
    string addStrings(string num1, string num2) {
        while(num1.size() && num2.size()){
            int sum= (num1.back() -'0' + num2.back() -'0' + carry) ;
            ans = (char)((sum%10) + '0') + ans;
            carry= sum/10;
            num1.pop_back();num2.pop_back();
        }

        while(num1.size()){
            int sum= (num1.back() -'0' + carry) ;
            ans = (char)((sum%10) + '0') + ans ;
            carry= sum/10;
            num1.pop_back();
        }
        while(num2.size()){
            int sum= (num2.back() -'0' + carry) ;
            ans = (char)((sum%10) + '0') + ans ;
            carry= sum/10;
            num2.pop_back();
        }
        if(carry) ans = (char)(carry+'0') + ans;
        return ans;

    }
};