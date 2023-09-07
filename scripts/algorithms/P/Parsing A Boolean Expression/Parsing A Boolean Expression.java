// Runtime: 1 ms (Top 98.8%) | Memory: 40.90 MB (Top 99.4%)

class Solution {
    
    int pos = 0;
    
    public boolean parseBoolExpr(String s) {
        pos = 0;
        return solve(s, '-');
    }
    
    public boolean solve(String s, char prev_sign) {
       
        boolean res = s.charAt(pos) == 'f' ? false : true;
        char cur_sign = ' ';
        int flag_res_init = 0;
        while(pos < s.length()) {
            
            char cur_char = s.charAt(pos++);
            
            if(isExpr(cur_char)){
                res = eval(cur_char == 't'?true:false, res , prev_sign);
            }
            else if(isSign(cur_char)){
                cur_sign = cur_char;
            }
            else if(cur_char == '('){
                if(flag_res_init == 1 || prev_sign == '!')
                    res = eval(solve(s, cur_sign), res, prev_sign);
                else {
                    res = solve(s, cur_sign);
                    flag_res_init = 1;
                }
            }
            else if(cur_char == ')'){
                 return res;
            }
            
        }
       return res;
    }
    
    public boolean isExpr(char c){
        return (c == 'f' || c == 't');
    }
    
    public boolean isSign(char c){
        return (c == '!' || c == '&' || c == '|');
    }
    
    public boolean eval(boolean e1, boolean e2, char sign) {
     
        boolean res = false;
        if(sign == '!')
            res = !e1;
        
        else if(sign == '|')
            res = e1 | e2;
        
        else if(sign == '&')
            res = e1&e2;
        
        return res;
    }
}