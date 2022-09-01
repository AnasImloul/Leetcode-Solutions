// Runtime: 17 ms (Top 28.66%) | Memory: 53.2 MB (Top 21.64%)
//Time Complexity O(Nlog(N)) - N is the number of intervals
//Space Complexity O(N) - N is the number of intervals, can be reduced to O(1) if needed
class Solution {
    public int intersectionSizeTwo(int[][] intervals) {
        //corner case: can intervals be null or empty? No

        //First, sort the intervals by end, then by reverse order start
        Arrays.sort(intervals, new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                if (a[1] == b[1]) {
                    return b[0] - a[0];
                }
                return a[1] - b[1];
            }
        });

        //Second, for each two intervals, greedily find if the previous interval would satisfy next interval's request
        List<Integer> list = new ArrayList<>(); //basically the ending set S, btw, we actually do not need this but I use it here for better intuition

        //add last two nums within the range
        list.add(intervals[0][1] - 1);
        list.add(intervals[0][1]);

        for (int i = 1; i < intervals.length; i++) {
            int lastOne = list.get(list.size() - 1);
            int lastTwo = list.get(list.size() - 2);

            int[] interval = intervals[i];
            int start = interval[0];
            int end = interval[1];

            //if overlaps at least 2
            if (lastOne >= start && lastTwo >= start) {
                continue;
            } else if (lastOne >= start) { //if overlaps 1
                list.add(end);
            } else { //if not overlapping
                list.add(end - 1);
                list.add(end);
            }
        }

        return list.size();
    }
}