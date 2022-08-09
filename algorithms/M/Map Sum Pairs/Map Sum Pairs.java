class MapSum {
    private Map<String, Integer> map;
    private Map<String, Integer> words;

    public MapSum() {
        this.map = new HashMap<>();
        this.words = new HashMap<>();
    }
    
    public void insert(String key, int val) {
        Integer lookup = this.words.getOrDefault(key, null);
        int diff;
        if (lookup == null)
            diff = val;
        else
            diff = val - lookup;
        
        int k = key.length();
        
        StringBuilder sb = new StringBuilder(); 
        for (int i = 0; i < k; i++) {
            sb.append(key.charAt(i));
            
            String prefix = sb.toString();
            map.put(prefix, map.getOrDefault(prefix, 0) + diff);
        }
        
        this.words.put(key, val);
    }
    
    public int sum(String prefix) {
        return this.map.getOrDefault(prefix, 0);
    }
}

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
