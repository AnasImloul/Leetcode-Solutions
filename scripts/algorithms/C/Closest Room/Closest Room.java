// Runtime: 164 ms (Top 39.53%) | Memory: 127.2 MB (Top 83.72%)
class Solution {
    public int[] closestRoom(int[][] rooms, int[][] queries) {
        int n = rooms.length, k = queries.length;
        Integer[] indexes = new Integer[k];
        for (int i = 0; i < k; i++) indexes[i] = i;
        Arrays.sort(rooms, (a, b) -> Integer.compare(b[1], a[1])); //Sort by decreasing order of room size
        Arrays.sort(indexes, (a, b) -> Integer.compare(queries[b][1], queries[a][1])); // Sort by decreasing order of query minSize
        TreeSet<Integer> roomIdsSoFar = new TreeSet<>();
        int[] ans = new int[k];
        int i = 0;
        for (int index : indexes) {
            while (i < n && rooms[i][1] >= queries[index][1]) { // Add id of the room which its size >= query minSize
                roomIdsSoFar.add(rooms[i++][0]);
            }
            ans[index] = searchClosetRoomId(roomIdsSoFar, queries[index][0]);
        }
        return ans;
    }
    int searchClosetRoomId(TreeSet<Integer> treeSet, int preferredId) {
        Integer floor = treeSet.floor(preferredId);
        Integer ceiling = treeSet.ceiling(preferredId);
        int ansAbs = Integer.MAX_VALUE, ans = -1;
        if (floor != null) {
            ans = floor;
            ansAbs = Math.abs(preferredId - floor);
        }
        if (ceiling != null && ansAbs > Math.abs(preferredId - ceiling)) {
            ans = ceiling;
        }
        return ans;
    }
}