class Solution {
    public int minMovesToSeat(int[] seats, int[] students) {
        Arrays.sort(seats);
        Arrays.sort(students);
        int diff = 0;
        for(int i=0; i<seats.length; i++){
            diff +=  Math.abs(students[i]-seats[i]);
        }
        return diff;
    }
}
