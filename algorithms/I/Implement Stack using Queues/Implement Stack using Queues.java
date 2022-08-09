class MyStack {
    
    Queue<Integer> queue = null;
    
    public MyStack() {
        queue =  new LinkedList<>();
    }
    
    public void push(int x) {
        
        Queue<Integer> tempQueue = new LinkedList<>();  
        tempQueue.add(x);  
        
        while(!queue.isEmpty()){
         tempQueue.add(queue.remove());
        }
        
        queue = tempQueue;
        
    }
    
    public int pop() {
       return queue.remove();
    }
    
    public int top() {
        return  queue.peek();
    }
    
    public boolean empty() {
        return queue.isEmpty();
    }
}
