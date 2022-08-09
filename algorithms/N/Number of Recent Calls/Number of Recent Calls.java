class RecentCounter {

    LinkedList<Integer> ll = new LinkedList<>();
    
    
    
    public RecentCounter() {
        ll.clear();
    }
    
    public int ping(int t) {
        ll.add(t);
        
        while(t-ll.peek() > 3000){
            ll.remove();
        }
            
        return ll.size();
    }
}

