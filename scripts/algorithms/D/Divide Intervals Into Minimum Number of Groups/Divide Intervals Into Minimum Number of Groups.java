class Solution {
    public int minGroups(int[][] intervals) {
        var treemap = new TreeMap<Integer, Integer>();

        for (int[] interval : intervals) {
            treemap.merge(interval[0], 1, Integer::sum);
            treemap.merge(interval[1] + 1, -1, Integer::sum);
        }

        int rooms = 0;
        int roomsNeeded = treemap.firstEntry().getValue();
        for (var entry : treemap.entrySet()) {
            rooms += entry.getValue();
            roomsNeeded = Math.max(roomsNeeded, rooms);
        }


        return roomsNeeded;

    }
}