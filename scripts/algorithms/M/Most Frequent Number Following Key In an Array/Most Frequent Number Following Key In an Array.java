// Runtime: 3 ms (Top 55.1%) | Memory: 43.05 MB (Top 60.9%)

class Solution {
    public int mostFrequent(int[] nums, int key) {
        int n=nums.length;
        HashMap<Integer,Integer> map=new HashMap<>();
        for(int i=0;i<n-1;i++){
            if(nums[i]==key){
                int target=nums[i+1];
                map.put(target,map.getOrDefault(target,0)+1);
            }
        }
        int max=0;
        int re=0;
        for(int x:map.keySet()){
            if(map.get(x)>max){
                re=x;
                max=map.get(x);
            }
        }
        return re;
    }
}