class Solution {
    public int mostFrequent(int[] nums, int key) {
        int freq[] = new int[1001];
        
        //count frequency of numbers which are followed by key
        for (int i = 1; i < nums.length; i++) {
            //if previous number is key
            //increase frequency of the number
            if (nums[i - 1] == key) { 
                freq[nums[i]]++;
            }
        }
        
        //check which number is most frequent
        int max = 0;
        for (int i = 1; i < freq.length; i++) {
            if (freq[i] > freq[max]) {
                max = i;
            }
        }
        
        //return
        return max;
    }
}
