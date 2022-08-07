class RandomizedCollection {
    List<Integer> multiSet;
    HashMap<Integer, PriorityQueue<Integer>> map;
    Random random;
    public RandomizedCollection() {
        map = new HashMap<>();
        multiSet = new ArrayList<>();
        random = new Random();
    }
    
    public boolean insert(int val) {
        boolean contains = map.containsKey(val);
        multiSet.add(val);
        PriorityQueue<Integer> pq;
        if(!contains){
            pq = new PriorityQueue<>(Collections.reverseOrder());
            map.put(val, pq);
        }else
            pq = map.get(val);
        
        pq.add(multiSet.size()-1);
        return !contains;
    }
    
    public boolean remove(int val) {
        if(!map.containsKey(val))
            return false;
        
        PriorityQueue<Integer> pq = map.get(val);
        int indexToRemove = pq.poll();
        if(pq.size() == 0) map.remove(val);
        
        int lastIndex = multiSet.size()-1;
        if(indexToRemove != lastIndex){
            int valLast = multiSet.get(lastIndex);
            PriorityQueue<Integer> temp = map.get(valLast);
            temp.poll();
            temp.add(indexToRemove);
            multiSet.set(indexToRemove, valLast);
        }
        multiSet.remove(lastIndex);
        return true;
    }
    
    public int getRandom() {
        int index = random.nextInt(multiSet.size());
        return multiSet.get(index);
    }
}
