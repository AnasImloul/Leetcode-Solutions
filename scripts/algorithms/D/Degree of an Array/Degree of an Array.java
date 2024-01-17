// Runtime: 15 ms (Top 84.55%) | Memory: 49.70 MB (Top 5.99%)

class Solution {
    public int findShortestSubArray(int[] nums) {
        // The int is an array of [firstEncounter, lastEncounter, frequency]
        HashMap<Integer, int[]> map = new HashMap<>();
        for(int i = 0; i < nums.length; i++){

            // If the key does not exist in the map, we put it with the first encounter and last encounter set to the current position, 'i', and the freqency 1
            if(!map.containsKey(nums[i])){
                map.put(nums[i], new int[]{i, i, 1});
            } 

            // If it does exist, we update the last encounter to the current position and we increase the frequency by 1
            else {
                int[] arr = map.get(nums[i]);
                arr[1] = i;
                arr[2]++;
                map.put(nums[i], arr);
            }
        }
        // Maximim frequency
        int maxFreq = Integer.MIN_VALUE;

        // Minimum distance
        int minDist = Integer.MAX_VALUE;

        // Going through all the values of the HashMap
        for(int[] value : map.values()){
            // value[0] = the first encounter index
            // value[1] = the last encounter index
            // value[2] = frequency

            // If the frecuency is greater than the maxFreq, then we update it and also set the minDist
            if(value[2] > maxFreq){
                maxFreq = value[2];
                minDist = value[1] - value[0] + 1;
            } 

            // If the frecuency is equal to the current max, we take the minimum between the exiting minDist and the minimum distance for the current value
            else if(value[2] == maxFreq){
                minDist = Math.min(minDist, value[1] - value[0] + 1);
            }
        }
        return minDist;
    }
}
