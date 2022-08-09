class DinnerPlates {
    
    List<Stack<Integer>> stack;
    PriorityQueue<Integer> leftEmpty;
    PriorityQueue<Integer> rightNonEmpty;
    int cap;
    public DinnerPlates(int capacity) {
        this.cap = capacity;
        this.stack = new ArrayList<>();
        this.leftEmpty = new PriorityQueue<>();
        this.rightNonEmpty = new PriorityQueue<>(Collections.reverseOrder());
        stack.add(new Stack<>());
        leftEmpty.offer(0);
    }
    
    public void push(int val) {
        while(!leftEmpty.isEmpty() && stack.get(leftEmpty.peek()).size() == cap) leftEmpty.poll();
        if(leftEmpty.isEmpty()) {
            stack.add(new Stack<>());
            leftEmpty.offer(stack.size() - 1);
        }
        Stack<Integer> s = stack.get(leftEmpty.peek());
        if(s.isEmpty()) rightNonEmpty.offer(leftEmpty.peek());
        s.push(val);
    }
    
    public int pop() {
        while(!rightNonEmpty.isEmpty() && stack.get(rightNonEmpty.peek()).isEmpty()) rightNonEmpty.poll();
        if(rightNonEmpty.isEmpty()) {
            return -1;
        }        
        Stack<Integer> s = stack.get(rightNonEmpty.peek());
        if(s.size() == cap) leftEmpty.offer(rightNonEmpty.peek());
        return s.pop();
    }
    
    public int popAtStack(int index) {
        if(index >= stack.size()) return -1;
        Stack<Integer> s = stack.get(index);
        if(s.isEmpty()) return -1;
        if(s.size() == cap) leftEmpty.offer(index);
        return s.pop();
    }
}

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates obj = new DinnerPlates(capacity);
 * obj.push(val);
 * int param_2 = obj.pop();
 * int param_3 = obj.popAtStack(index);
 */