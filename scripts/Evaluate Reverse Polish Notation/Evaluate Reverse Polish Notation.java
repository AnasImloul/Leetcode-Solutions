class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack();
        for(String i: tokens){
            if(i.equals("+") || i.equals("-") || i.equals("*") || i.equals("/")){
                int a = stack.pop();
                int b = stack.pop();
                int temp = 0;
                if(i.equals("+"))
                    temp = a+b;
                else if(i.equals("-"))
                    temp = b-a;
                else if(i.equals("*"))
                    temp = a*b;
                else if(i.equals("/"))
                    temp = b/a;
                stack.push(temp);
            }
            else
                stack.push(Integer.parseInt(i));
        }
        return stack.pop();
    }
}
