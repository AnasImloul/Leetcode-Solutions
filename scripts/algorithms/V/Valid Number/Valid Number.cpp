// Runtime: 0 ms (Top 100.00%) | Memory: 5.8 MB (Top 94.26%)
/*
Max Possible combination of characters in the string has followig parts(stages) :
            +/- number . number e/E +/- number
stages: 0 1 2 3 4 5 6 7

Now check each characters at there correct stages or not and increament the stage
as per the character found at ith position.

*/

class Solution {
public:
    bool isNumber(string s){
        char stage = 0;
        for(int i = 0; i<s.size(); ++i){
            if( (s[i] == '+' || s[i] == '-') && (stage == 0 || stage == 5)){ stage++; }
            else if((s[i] == 'e' || s[i] == 'E') && stage > 1 && stage < 5){ stage = 5; }
            else if(s[i] == '.' && stage < 3) {
                //both side of '.' do not have any digit then return false
                if(stage <= 1 && ( i + 1 >= s.size() || !(s[i+1] >= '0' && s[i+1] <= '9')) ) return false;
                stage = 3;
            }else if(s[i] >= '0' && s[i] <= '9'){
                if(!(stage == 2 || stage == 4 || stage == 7) ) stage++;
                if(stage == 1 || stage == 6 ) stage++;
            }else return false;
        }
        if(stage <= 1 || stage == 5 || stage == 6) return false;
        return true;
    }
};