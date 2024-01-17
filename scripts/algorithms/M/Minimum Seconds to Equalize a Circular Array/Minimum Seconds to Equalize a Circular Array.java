// Runtime: 71 ms (Top 70.83%) | Memory: 80.90 MB (Top 44.44%)

class Solution {
   public int minimumSeconds(List<Integer> nums) {
        // we replace the number at i with i-1 or i+1
        int n = nums.size();
        int ans = n - 1; // assuming all numbers are different

        // store all indexes of the same number
        Map<Integer, List<Integer>> m = new HashMap<>();

        for (int i = 0; i < n; i++) {
            if (!m.containsKey(nums.get(i))) {
                m.put(nums.get(i), new ArrayList<>());
            }
            m.get(nums.get(i)).add(i);
        }

        for (Map.Entry<Integer, List<Integer>> entry : m.entrySet()) { // traverse all the different numbers
            List<Integer> v = entry.getValue(); // all the indexes of the same number
            int len = v.size(); // size of list
            // now we change all remaining numbers = total size of the array - size of the same number
            int maxi = (n - 1) - (v.get(len - 1) - v.get(0));
            for (int j = 1; j < len; j++) {
                // maximum difference between adjacent indexes
                maxi = Math.max(maxi, v.get(j) - v.get(j - 1) - 1);
            }
            // minimize the maximum distance between any numbers
            ans = Math.min(ans, maxi);
        }

        // we traverse in both directions at the same time, so we give half of the answer
        return (ans + 1) / 2;
    }
}    
