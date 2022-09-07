// Runtime: 8 ms (Top 22.27%) | Memory: 6.2 MB (Top 89.57%)
class Solution {
public:
    int numSteps(string s) {
        int n=0;
        bool carry = false;
        int steps = 0;
        if(s == "1") return 0;
        while(s.length() > 0){
            int i = s.length()-1;
            if(carry){
                if(s[i] == '1'){
                    carry = true; s[i] = '0';
                }else{
                    s[i] = '1'; carry = false;
                }
            }
            if(s[i] == '0'){ s.pop_back(); steps++;}
            else{carry = true; s.pop_back(); steps += 2;}
            if(s == "1"){
                if(carry) steps++;
                break;
            }
        }
        return steps;
    }
};