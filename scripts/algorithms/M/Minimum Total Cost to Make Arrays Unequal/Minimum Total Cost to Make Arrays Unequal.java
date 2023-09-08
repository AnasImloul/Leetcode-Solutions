// Runtime: 25 ms (Top 23.5%) | Memory: 59.53 MB (Top 23.5%)

class Solution {
    public long minimumTotalCost(int[] nums1, int[] nums2) {
        long res = 0;
        Map<Integer,Integer> map = new HashMap<>();
        for(int i=0;i<nums1.length;i++){
            if(nums1[i]==nums2[i]){
                map.put(nums1[i],map.getOrDefault(nums1[i],0)+1);
                res += i;
            }
        }
        int val = 0 , size = 0;
        for(Integer key:map.keySet()){
            if(map.getOrDefault(key,0) >= map.getOrDefault(val,0))
                val = key;
            size += map.get(key);
        }
        for(int i=0;i<nums1.length;i++){
            if(nums1[i]==val || nums2[i]==val || nums1[i] == nums2[i] || size >= 2 * map.getOrDefault(val,0))
                continue;
            map.put(nums1[i],map.getOrDefault(nums1[i],0)+1);
            size++;
            res += i;
        }
        return 2 * map.getOrDefault(val,0) <= size ? res : -1;
    }
}