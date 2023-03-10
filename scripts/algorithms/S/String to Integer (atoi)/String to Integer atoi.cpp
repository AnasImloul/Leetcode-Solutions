/*

    Time Complexity : O(logN), Since we are going through the entire number digit by digit, the time complexity
    should be O(log10N). The reason behind log10 is because we are dealing with integers which are base 10.

    Space Complexity : O(1), We are not using any data structure for interim operations, therefore, the space
    complexity is O(1).

    Solved using String.

*/

class Solution {
public:
    int myAtoi(string s) {
        int len = s.size();
        double num = 0;
        int i=0;
        while(s[i] == ' '){
            i++;
        }
        bool positive = s[i] == '+';
        bool negative = s[i] == '-';
        positive == true ? i++ : i;
        negative == true ? i++ : i;
        while(i < len && s[i] >= '0' && s[i] <= '9'){
            num = num*10 + (s[i]-'0');
            i++;
        }
        num = negative ? -num : num;
        cout<<num<<endl;
        num = (num > INT_MAX) ? INT_MAX : num;
        num = (num < INT_MIN) ? INT_MIN : num;
        cout<<num<<endl;
        return int(num);
    }
};
