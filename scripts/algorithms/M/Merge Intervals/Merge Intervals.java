// Runtime: 12 ms (Top 74.73%) | Memory: 55.4 MB (Top 43.78%)
class Solution {
    public int[][] merge(int[][] intervals) {
        // sort
        // unknown size of ans = use ArrayList
        // insert from back
            // case 1 : Merging
                // start of new interval is less that end of old interval
                // new end = Math.max(new intervals end, old intervals end)
            // case 2 : Non-merging
                // seperate interval
        // convert ArrayList to array and return

        Arrays.sort(intervals, (a,b) -> a[0]-b[0]);
        ArrayList<int[]> list = new ArrayList<>();
        for(int i = 0; i < intervals.length; i++) {
            if(i == 0) {
                list.add(intervals[i]);
            } else {
                int[] prev = list.get(list.size()-1);
                int[] curr = intervals[i];
                if(curr[0] <= prev[1]) {
                    prev[1] = Math.max(curr[1], prev[1]);
                }else {
                    list.add(curr);
                }
            }
        }
        return list.toArray(new int[list.size()][2]);
    }
}