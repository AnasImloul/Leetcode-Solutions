// Runtime: 125 ms (Top 39.80%) | Memory: 117.7 MB (Top 6.97%)
class Solution {
    public int[] maxNumber(int[] nums1, int[] nums2, int k) {
        String ans="";
        for (int i = Math.max(0, k-nums2.length); i <= Math.min(nums1.length, k); i++){ // try all possible lengths from each seq
            String one = solve(nums1, i); // find the best seq matching len of i
            String two = solve(nums2, k-i); // len of k-i
            StringBuilder sb = new StringBuilder();
            int a = 0, b = 0;
            while(a < i || b < k-i){ // merge it to the max
                sb.append(one.substring(a).compareTo(two.substring(b))>=0?one.charAt(a++):two.charAt(b++));
            }
            if (sb.toString().compareTo(ans)>0){ // if better, we replace.
                ans=sb.toString();
            }
        }
        int[] res = new int[k];
        for (int i = 0; i < k;++i){
            res[i]=ans.charAt(i)-'0';
        }
        return res;
    }

    private String solve(int[] arr, int k){
        Deque<Integer> stack = new ArrayDeque<>();
        for (int i = 0;i<arr.length;++i){
            while(!stack.isEmpty()&&arr.length-i+stack.size()>k&&stack.peek()<arr[i]){
                stack.pop();
            }
            stack.push(arr[i]);
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < k;i++){
            sb.append(stack.pollLast());
        }
        return sb.toString();
    }
}