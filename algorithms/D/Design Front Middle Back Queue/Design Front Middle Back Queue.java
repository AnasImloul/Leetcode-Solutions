class FrontMiddleBackQueue {
    LinkedList<Integer> list;
    
    public FrontMiddleBackQueue() {
        list = new LinkedList();
    }
    
    public void pushFront(int val) {
        list.add(0, val);
    }
    
    public void pushMiddle(int val) {
        list.add(list.size() / 2, val);
    }
    
    public void pushBack(int val) {
        list.add(val);
    }
    
    public int popFront() {
        if(isEmpty()) return -1;
       
        return list.remove(0);
    }
    
    public int popMiddle() {
        if(isEmpty()) return -1;
        
        return list.remove(findMiddleIndex());
    }
    
    public int popBack() {
        if(isEmpty()) return -1;
        
        return list.remove(list.size() - 1);
    }
    
    private boolean isEmpty(){
        return list.isEmpty();
    }
    
    private int findMiddleIndex(){
        return (list.size() - 1) / 2;
    }
    

}
