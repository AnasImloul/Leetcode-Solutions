// Runtime: 0 ms (Top 100.0%) | Memory: 6.40 MB (Top 36.99%)

/*
For mm there is no specific condition its as simple as 10 variation for last '?' and 6 variation for second last '?'
For hh, there are three cases:
1. when both hh are ?? => simply results in 24 variation
2. whne first is ? and second is not => Again two cases, when non '?' is less than 4 ( 3 variations ) & greater than equal to 4 ( only 2 variations).
3.When second is ? and first is not => Again two cases, if non '?' is 2 or not. if equl to 2 => 4 variations other wise 10 variations.
*/

class Solution {
public:
    int countTime(string time) {
        int ans = 1;
        if(time[4] == '?') ans = ans * 10;
        if(time[3] == '?') ans = ans * 6;
        
        if(time[0] == '?' && time[1] == '?') ans = ans * 24;
        else{
            if(time[1] == '?'){ 
                if(time[0] == '2' ) ans = ans * 4;
                else ans = ans * 10;
            }
            if(time[0] == '?'){
                if(time[1] < '4') ans = ans * 3;
                else ans = ans * 2;
            }
        }
        return ans;
    }
};
