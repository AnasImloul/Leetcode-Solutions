class RangeFreqQuery {
    //Use map's key to store arr's value, map's value to keep <value's location, cummulative arr's value count>
    HashMap<Integer, TreeMap<Integer, Integer>> map;
    public RangeFreqQuery(int[] arr) {
        //O(nlog(n))
        map = new HashMap<>();
        for(int i = 0; i < arr.length; i++){
            map.putIfAbsent(arr[i], new TreeMap<>());
            TreeMap<Integer, Integer> tree = map.get(arr[i]);
            //i = value's location
            //tree.size() = cummulative arr's value count - 1
            tree.put(i, tree.size());
        }
    }
    
    public int query(int left, int right, int value) {
        //O(log(n))
        
        //check if value exist in map
        if(!map.containsKey(value)){
            return 0;
        }
        TreeMap<Integer, Integer> tree = map.get(value);
        
        //check if there exist position >= left and position <= right
        //if not, return 0
        if(tree.ceilingKey(left) == null || tree.floorKey(right) == null){
            return 0;
        }
        //get leftMost position's cummulative count
        int leftMost = tree.get(tree.ceilingKey(left));
        //get rightMost position's cummulative count
        int rightMost = tree.get(tree.floorKey(right));
        
        return rightMost - leftMost + 1;
    }
}

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery obj = new RangeFreqQuery(arr);
 * int param_1 = obj.query(left,right,value);
 */
