class StockRecord {
    int timestamp;
    int price;
    
    public StockRecord(){}
    
    public StockRecord(int t, int p) {
        timestamp = t;
        price = p;
    }
}

class StockPrice {
    
    PriorityQueue<StockRecord> max = new PriorityQueue<>((sr1, sr2) -> (sr2.price - sr1.price));
    PriorityQueue<StockRecord> min = new PriorityQueue<>((sr1, sr2) -> (sr1.price - sr2.price));
    StockRecord current_record;
    Map<Integer, Integer> map = new HashMap<>();

    
    public StockPrice() {
        current_record = new StockRecord();
    }
    
    public void update(int timestamp, int price) {
        if(timestamp >= current_record.timestamp) {
            current_record.timestamp = timestamp;
            current_record.price = price;
        }
        
        StockRecord sr = new StockRecord(timestamp, price);
        max.add(sr);
        min.add(sr);
        map.put(timestamp, price);
    }
    
    public int current() {
        return current_record.price;
    }
    
    public int maximum() {
        StockRecord sp = max.peek();
        while(true) {
            sp = max.peek();
            if(sp.price != map.get(sp.timestamp))
                max.poll();
            else break;
        }
        return sp.price;
    }
    
    public int minimum() {
        StockRecord sp = min.peek();
         while(true) {
            sp = min.peek();
            if(sp.price != map.get(sp.timestamp))
                min.poll();
            else break;
        }
        return sp.price;
    }
}
