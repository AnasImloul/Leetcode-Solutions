class Solution {
    public boolean parseBoolExpr(String expression) {
        Deque<Boolean> stack = new ArrayDeque<>();
        Deque<Character> op = new ArrayDeque<>();
        Deque<Character> p  = new ArrayDeque<>();
        for (char ch : expression.toCharArray()){
            switch(ch){
                case '!', '&', '|' -> p.push(ch);
                case 'f', 't' -> stack.push(ch == 't');
                case '(' -> {op.push(ch); if (p.peek() == '!') op.push('!');}
                case ')' -> {go(op, stack); op.pop(); p.pop();}
                default  -> {go(op, stack); op.push(p.peek());}
            };
        }
        go(op, stack);
        return stack.pop();
    }

    private void go(Deque<Character> op, Deque<Boolean> stack){
        while(!op.isEmpty() && op.peek() != '('){
            switch(op.pop()){
                case '|' -> stack.push(stack.pop() | stack.pop());
                case '&' -> stack.push(stack.pop() & stack.pop());
                default  -> stack.push(!stack.pop());
            };
        }
    }
}
