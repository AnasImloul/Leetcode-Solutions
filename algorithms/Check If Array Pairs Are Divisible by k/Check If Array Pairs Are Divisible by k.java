class Solution {
    public boolean canArrange(int[] arr, int k) {
        int n = arr.length; 
        HashMap<Integer, Integer> map = new HashMap<>(); // stores <remainder, count>
        
        for(int num : arr){
            int rem = num % k; 
            if(rem < 0) rem+=k;
            map.put(rem, map.getOrDefault(rem, 0) + 1); 
        }
        
        for(int r : map.keySet()){
            if(r == 0){ 
                if(map.get(r) % 2 != 0) return false;
            } 
            else if(r * 2 == k){
                if(map.get(r) % 2 != 0) return false;
            }
            else{
               int count1 = map.get(r); 
               int count2 = map.getOrDefault(k-r, 0); 
               if(count1!=count2) return false; 
            }
        }
        return true; 
    }
}
