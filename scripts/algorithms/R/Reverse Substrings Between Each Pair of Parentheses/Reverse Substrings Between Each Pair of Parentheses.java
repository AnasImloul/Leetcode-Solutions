// Runtime: 6 ms (Top 52.91%) | Memory: 42.5 MB (Top 42.22%)
class Solution {
    public String reverseParentheses(String s) {
        Stack<String> stack = new Stack<>();

        int j = 0;
        while(j < s.length()){
            /*
                We need to keep on adding whatever comes
                as long as it is not a ')'.
            */
            if(s.charAt(j) != ')')
                stack.push(s.charAt(j)+"");

            /*
                Now that we have encountered an ')', its time
                to start popping from top of stack unless we find an opening
                parenthesis

                then we just need to reverse the string formed by popping
                and put it back on stack.

                Try dry running and it will all make sense
            */
            else{
                StringBuilder sb = new StringBuilder();
                while(!stack.isEmpty() && !stack.peek().equals("(")){
                    sb.append(stack.pop());
                }

                stack.pop();
                stack.push(sb.reverse().toString());
            }
            j++;
        }

        /*
            We have our result string in the stack now,
            we just need to pop it and return the reverse of it.
        */
        StringBuilder res = new StringBuilder();
        while(!stack.isEmpty())
            res.append(stack.pop());

        return res.reverse().toString();
    }
}