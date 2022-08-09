class Solution {
public:
    string removeDigit(string number, char digit) {
        string res = "";
        for(int i=0; i<number.size(); i++){
            if(number[i] == digit){
                string temp = number.substr(0, i) + number.substr(i+1);
                res = max(res, temp);
            }
        }
        return res;
    }
};
