// Runtime: 18 ms (Top 78.7%) | Memory: 55.94 MB (Top 56.9%)

class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        List<List<Integer>> ans=new ArrayList<>();
        Arrays.sort(arr);
        int min=Integer.MAX_VALUE;
        for(int i=0;i<arr.length-1;i++){
            int diff=Math.abs(arr[i]-arr[i+1]);
            if(diff<min)
            {
            min=diff;
            }
        }
        for(int i=0;i<arr.length-1;i++){
            int diff=Math.abs(arr[i]-arr[i+1]);
            if(diff==min){
                 List<Integer> pair=new ArrayList<>(2);
                pair.add(arr[i]);
                pair.add(arr[i+1]);
                ans.add(pair);
            }
        }
        return ans;
    }
}