class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
        int start = -1;
        int count = 0;
        
        int max = 0;
        int curr = 0;
        
        for (int i = 0; i < customers.length; i++) {
            if (grumpy[i] == 0) {
                count += customers[i];
            } else {
                curr += customers[i];
            }
            
            if (i-start > minutes) {
                start++;
                if (grumpy[start] == 1) {
                    curr -= customers[start];
                }
            }
            max = Math.max(max, curr);
        }
        
        return count + max;
    }
}
