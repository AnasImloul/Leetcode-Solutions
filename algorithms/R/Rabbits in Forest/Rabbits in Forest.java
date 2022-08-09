class Solution {
    public int numRabbits(int[] answers) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int count = 0;
        
        for(int ele : answers) {
            
            if(!map.containsKey(ele+1)) {
                map.put(ele+1, 1);
                count += ele+1;
            }
            else if(map.get(ele+1) == ele+1) {
                map.put(ele+1, 1);
                 count += ele+1;
            }
            else {
                int freq = map.get(ele+1);
                map.put(ele+1, freq+1);
            }
        }
        
        return count;
    }
}
