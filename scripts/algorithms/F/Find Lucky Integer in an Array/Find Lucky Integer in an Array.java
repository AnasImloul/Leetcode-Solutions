// Runtime: 12 ms (Top 12.82%) | Memory: 44.3 MB (Top 18.67%)
class Solution {
    public int findLucky(int[] arr) {
        HashMap<Integer,Integer> map = new HashMap<>();
        for(int i : arr){
            map.put(i, map.getOrDefault(i,0)+1);
        }
        System.out.print(map);
         int max = 0;
        for (Map.Entry<Integer, Integer> e : map.entrySet()){
           int temp = 0;
            if(e.getKey() == (int)e.getValue()){
                temp = (int)e.getKey();
            }
            if(max < temp){
                max= temp;
            }
        }
         if(max != 0)return max;
        return -1;
    }
}