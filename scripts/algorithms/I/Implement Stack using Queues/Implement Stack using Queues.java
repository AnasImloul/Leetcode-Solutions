// Runtime: 1 ms (Top 34.13%) | Memory: 42.2 MB (Top 19.29%)
class MyStack {

    Queue<Integer> queue = null;

    public MyStack() {
        queue = new LinkedList<>();
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
        return queue.peek();
    }

    public boolean empty() {
        return queue.isEmpty();
    }
}