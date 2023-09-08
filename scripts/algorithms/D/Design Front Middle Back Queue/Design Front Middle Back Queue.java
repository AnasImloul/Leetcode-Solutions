// Runtime: 7 ms (Top 73.3%) | Memory: 44.18 MB (Top 74.0%)

class FrontMiddleBackQueue {

    Deque<Integer> dq1, dq2;
    public FrontMiddleBackQueue() {        
        dq1 = new ArrayDeque<Integer>();
        dq2 = new ArrayDeque<Integer>();
    }
    
    public void pushFront(int val) {
        dq1.addFirst(val);
    }    
    
    public void pushBack(int val) {
        dq2.addLast(val);
    }   
    
    public void pushMiddle(int val) {
        while(dq1.size() + 1 < dq2.size())
            dq1.addLast(dq2.removeFirst());       
        while(dq1.size() > dq2.size())
            dq2.addFirst(dq1.removeLast());        
        dq1.addLast(val);        
    }     
    
    public int popFront() {
        if(!dq1.isEmpty())
            return dq1.removeFirst();
        if(!dq2.isEmpty())
            return dq2.removeFirst();
        return -1;    
    }  
    
    public int popMiddle() {
        if(dq1.isEmpty() && dq2.isEmpty())
            return -1;        
        while(dq1.size() < dq2.size())
            dq1.addLast(dq2.removeFirst());     
        while(dq1.size() > dq2.size() + 1)
            dq2.addFirst(dq1.removeLast());
        return !dq1.isEmpty() ? dq1.removeLast() : dq2.removeFirst();
    }    
    
    public int popBack() {
        if(!dq2.isEmpty())
            return dq2.removeLast();
        if(!dq1.isEmpty())
            return dq1.removeLast();
        return -1;            
    }    
}