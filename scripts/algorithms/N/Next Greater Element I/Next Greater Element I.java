// Runtime: 6 ms (Top 51.94%) | Memory: 44.9 MB (Top 8.50%)
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
       HashMap<Integer, Integer> map = new HashMap<>();
       Stack<Integer> stack = new Stack<>();
        int[] ans = new int[nums1.length];
        for(int i = 0; i < nums2.length; i++){
            while(!stack.isEmpty() && nums2[i] > stack.peek()){
                int temp = stack.pop();
                map.put(temp, nums2[i]);
            }
            stack.push(nums2[i]);
        }
        for(int i = 0; i < nums1.length; i++){
           ans[i] = map.getOrDefault(nums1[i], -1);
        }
        return ans;
    }
}