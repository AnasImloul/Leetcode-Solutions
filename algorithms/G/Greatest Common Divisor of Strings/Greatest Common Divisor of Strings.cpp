class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int m = str1.length(), n = str2.length();
        int temp = __gcd(m, n);
        string str;
        if(str1 + str2 == str2 + str1) str = str1.substr(0, temp);
        return str;
    }
};
