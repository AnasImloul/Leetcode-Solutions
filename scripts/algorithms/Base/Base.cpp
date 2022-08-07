Method 1 :- 
---------------
class Solution {
public:
    string convertToBase7(int num) {
        if(num < 0) 
            return "-" + convertToBase7(-num);
        else if(num < 7)
            return to_string(num);
        else
            return convertToBase7(num/7) + convertToBase7(num%7);
    }
};

Method 2 :-
---------------
class Solution {
public:
    string convertToBase7(int num) {
        string res = "";
        int num1 = num;
        if(num == 0)
            return "0";
        num = abs(num);
        while(num > 0)
        {
            res += to_string(num % 7);
            num = num/7;
        }
        reverse(res.begin(),res.end());
        if(num1 < 0)
            res = "-" + res;
        return res;
    }
};
