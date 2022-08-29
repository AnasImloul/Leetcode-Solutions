// Runtime: 119 ms (Top 71.43%) | Memory: 11.7 MB (Top 68.32%)
class Solution {
public:
    bool memo[50][50][2000];
    bool comp_seqs(string& s1, string& s2, int i1, int i2, int diff){
        // check true condition
        if(i1 == s1.size() && i2 == s2.size())
            return diff == 0;
        // add 1000 to 'diff' be in range [0, 2000)
        bool& ret = memo[i1][i2][diff+1000];
        if(ret)
            return false; // immediately return
        ret = true; // check visited

        // diff > 0 or diff < 0 checking to ensure the diff always be in range (-1000, 1000)
        // in the case that s1[i1] is a digit
        if(diff >= 0 && i1 < s1.size() && s1[i1] <= '9'){
            int num1 = 0;
            for(int i=0; i<min(3, (int)s1.size()-i1); i++){ // loop maximum 3 consecutive digits
                if(s1[i1 + i] > '9')
                    break;
                num1 = num1*10 + s1[i1 + i] - '0';
                if(comp_seqs(s1, s2, i1+i+1, i2, diff-num1))
                    return true;
            }
        }else if(diff <= 0 && i2 < s2.size() && s2[i2] <= '9'){ // in the case that s2[i2] is a digit
            int num2 = 0;
            for(int i=0; i<min(3, (int)s2.size()-i2); i++){
                if(s2[i2 + i] > '9')
                    break;
                num2 = num2*10 + s2[i2 + i] - '0';
                if(comp_seqs(s1, s2, i1, i2+i+1, diff+num2))
                    return true;
            }
        }else if(diff == 0){
            if(i1 >= s1.size() || i2 >= s2.size() || s1[i1] != s2[i2]) // reject infeasible cases
                return false;
            return comp_seqs(s1, s2, i1+1, i2+1, 0);
        }else if(diff > 0){
            if(i1 >= s1.size()) // reject infeasible cases
                return false;
            return comp_seqs(s1, s2, i1+1, i2, diff - 1);
        }else{
            if(i2 >= s2.size()) // reject infeasible cases
                return false;
            return comp_seqs(s1, s2, i1, i2+1, diff + 1);
        }
        return false;
    }
    bool possiblyEquals(string s1, string s2) {
        return comp_seqs(s1, s2, 0, 0, 0);
    }
};