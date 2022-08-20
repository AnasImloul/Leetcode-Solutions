// Runtime: 3 ms (Top 94.41%) | Memory: 46.4 MB (Top 56.41%)

class Solution {
    public List<Integer> intersection(int[][] nums) {

        List<Integer> ans = new ArrayList<>();

        int[] count = new int[1001];

        for(int[] arr : nums){
            for(int i : arr){
                count[i]++;
            }
        }

       for(int i=0;i<count.length;i++){
           if(count[i]==nums.length){
               ans.add(i);
           }
       }

        return ans;
    }
}
