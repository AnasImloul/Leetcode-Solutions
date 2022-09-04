// Runtime: 2 ms (Top 30.57%) | Memory: 41 MB (Top 56.77%)
class Solution {
    public int binaryGap(int n) {
      char[] arr = Integer.toBinaryString(n).toCharArray();
        List<Integer> ans = new ArrayList();
        for(int i = 0; i < arr.length ; i++){
            if(arr[i] == '1')
                ans.add(i);
        }
        int res = 0;
        for ( int i = 0 ; i < ans.size() -1 ; i++){
            res =Math.max(res,ans.get(i+1) - ans.get(i));
        }
        return res;
    }
}