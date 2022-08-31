// Runtime: 12 ms (Top 6.92%) | Memory: 49.9 MB (Top 21.03%)

class Solution {
    public int maxDistToClosest(int[] seats) {
        int size = seats.length;
        int max = 0;
        int start = -1;
        int end = -1;

        for(int i = 0; i<size; i++){
            if(seats[i] != 0){
                start = end; // update start to end when we have a filled seat.
                end = i; // update end with i pointer when we have a filled seat.
                if(start == -1) max = i; // for special case when there is only '1' in the array
                else max = Math.max((end-start)/2,max); // updating max.
            }
        }

        // Handeling speical cases before returning max.
        // 1) last element is 0 as we wont be updating max for that in above loop.
        // 2) when there only single '1' in the array, we need to make sure whether right half is bigger than the left half.

        if(seats[size - 1] == 0 || start == -1) return Math.max(max, (size - 1 - end));
        return max;
    }
}
