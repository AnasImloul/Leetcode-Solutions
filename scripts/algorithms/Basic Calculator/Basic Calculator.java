class Solution {
    int idx; // this index traverse the string in one pass, between different level of recursion
    public int calculate(String s) {
        idx = 0; // Initialization should be here
        return helper(s);
    }
    
    private int helper(String s) {
        int res = 0, num = 0, preSign = 1, n = s.length();
        while (idx < n) {
            char c = s.charAt(idx++);
            if (c == '(') num = helper(s); // Let recursion solve the sub-problem
            else if (c >= '0' && c <= '9') num = num * 10 + c - '0';
            if (c == '+' || c == '-' || c == ')' || idx == n) { // we need one more calculation when idx == n
                res += preSign * num;
                if (c == ')') return res; // end of a sub-problem
                num = 0;
                preSign = c == '+' ? 1 : -1;
            }
        }
        return res;
    }
}
