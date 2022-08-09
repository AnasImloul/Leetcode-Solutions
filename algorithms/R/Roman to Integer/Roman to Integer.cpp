class Solution {
public:
int getRoman(char c){
    switch (c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L' :
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}
int romanToInt(string s){
    int result = 0;
    for(int i = 0; i<s.size();i++){
        int num = getRoman(s[i]);
        int numNext = getRoman(s[i+1]);
        if(num>=numNext){
            result = result+num;
        }
        if(num<numNext){
            numNext = numNext-num;
            result = result+numNext;
            i++;
        }
    }
    return result;
}
};
