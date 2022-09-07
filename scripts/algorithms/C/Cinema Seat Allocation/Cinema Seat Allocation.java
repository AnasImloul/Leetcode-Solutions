// Runtime: 37 ms (Top 66.38%) | Memory: 70.8 MB (Top 57.25%)
class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        Map<Integer, int[]> seats = new HashMap<>();
        int availableSlots = 2 * n; // max available slots since each empty row could fit at max 2 slots

        for (int[] seat: reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            int[] slots = seats.getOrDefault(row, new int[3]);

            if (col >= 2 && col <= 5) { // left slot
                slots[0] = 1;
            }
            if (col >= 4 && col <= 7) { // middle slot
                slots[1] = 1;
            }
            if (col >= 6 && col <= 9) { // right slot
                slots[2] = 1;
            }

            seats.put(seat[0], slots);
        }

        for (int[] slots: seats.values()) {
            int taken = slots[0] + slots[2];

            if (taken == 2) { // both slots at either ends are taken
                if (slots[1] == 0) { // check if middle slot not taken
                    availableSlots--; // reduce availableslots by 1 since middle slot is available
                } else {
                    availableSlots -= 2; // entire row not available - reduce by 2
                }
            } else if (taken == 1) { // one of the slots at either ends are taken
                availableSlots--; // reduce by 1 since either side of the slots not available
            } else {
                continue; // entire row is available - no need to reduce the available slots
            }
        }

        return availableSlots;
    }
}