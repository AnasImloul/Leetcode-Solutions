// Runtime: 7 ms (Top 58.51%) | Memory: 43 MB (Top 43.86%)
class Solution {
    public String removeOuterParentheses(String s) {
    // if '(' check stack size > 0 add ans else not add ans
        // if ')' check stack size > 0 add ans else not add ans
        Stack<Character> st = new Stack<>();
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<s.length();i++){
            char ch = s.charAt(i);

            if(ch == '('){
                if(st.size() > 0){
                    sb.append(ch);
                }
                st.push(ch);
            }

            else{
                st.pop();
                if(st.size() > 0){
                    sb.append(ch);
                }
            }
        }
        return sb.toString();
    }
}