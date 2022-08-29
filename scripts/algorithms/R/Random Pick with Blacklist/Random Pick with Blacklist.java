// Runtime: 432 ms (Top 5.05%) | Memory: 74.1 MB (Top 5.26%)
class Solution {
    HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
    LinkedList<Integer> list = new LinkedList();
    int size = 0;
    public Solution(int n, int[] blacklist) {
        size = n - blacklist.length;
        for(int i: blacklist){
            map.put(i,-1);
            if(i < size ){
                list.add(i);
            }
        }
        int index = 0;
        for(int i = size; i < n; i++){
            if(!map.containsKey(i)){
                map.put(list.get(index),i);
                index += 1;
            }
        }
    }

    public int pick() {
        Random rand = new Random();
        int index = rand.nextInt(size);
        if(map.containsKey(index)){
            return map.get(index);
        }else{
            return index;
        }
    }
}