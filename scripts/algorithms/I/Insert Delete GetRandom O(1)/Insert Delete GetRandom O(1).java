class RandomizedSet {
    HashMap<Integer, Integer> map;
    ArrayList<Integer> list;
    Random rand;
    public RandomizedSet() {
        map = new HashMap<>();
        list = new ArrayList<>();
        rand = new Random();
    }
    
    public boolean insert(int val) {
        if (!map.containsKey(val)){
            map.put(val, list.size());
            list.add(val);
            return true;
        }
        return false;
    }
    
    public boolean remove(int val) {
        if (map.containsKey(val)){
            int index = map.get(val);
            int last = list.get(list.size() - 1);
            if (index != list.size() - 1){
                list.set(index, last);
                map.put(last, index);
            }
            list.remove(list.size() - 1);  
            map.remove(val);
            return true;
        }
        return false;
    }
    
    public int getRandom() {
        int r = rand.nextInt(list.size());   
        return list.get(r);
    }
}
