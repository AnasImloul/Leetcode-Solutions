// Runtime: 5 ms (Top 38.7%) | Memory: 44.24 MB (Top 53.3%)

class MyCircularQueue {

    private int front;
    private int rear;
    private int[] arr;
    private int cap;
    
    private int next(int i){ // to get next idx after i in circular queue
        return (i+1)%cap;
    }
    private int prev(int i){ // to get prev idx before i in circular queue
        return (i+cap-1)%cap;
    }
    
	// rest is as simple as implmenting a normal queue using array.
    public MyCircularQueue(int k) {
        arr = new int[k];
        cap=k;
        front=-1;
        rear=-1;
    }
    
    public boolean enQueue(int value) {
        if(isFull())return false;
        if(front==-1){
            front=0;
            rear=0;
            arr[rear]=value;
            return true;
        }
        rear = next(rear);
        arr[rear]=value;
        return true;
    }
    
    public boolean deQueue() {
        if(isEmpty())return false;
        if(front==rear){
            front=-1;
            rear=-1;
            return true;
        }
        front=next(front);
        return true;
    }
    
    public int Front() {
        if(front==-1)return -1;
        return arr[front];
    }
    
    public int Rear() {
        if(rear==-1)return -1;
        return arr[rear];
    }
    
    public boolean isEmpty() {
        return front==-1;
    }
    
    public boolean isFull() {
        return front!=-1 && next(rear)==front;
    }
}