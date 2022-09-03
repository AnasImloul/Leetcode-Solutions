// Runtime: 197 ms (Top 36.54%) | Memory: 54.3 MB (Top 59.44%)
class MyCalendarThree {

    TreeMap<Integer, Integer> map;
    public MyCalendarThree() {
        map = new TreeMap<>();
    }

    public int book(int start, int end) {
        if(map.isEmpty()){
            map.put(start, 1);
            map.put(end,-1);
            return 1;
        }

        //upvote if you like the solution

        map.put(start, map.getOrDefault(start,0)+1);
        map.put(end, map.getOrDefault(end,0)-1);

        int res = 0;
        int sum = 0;
        for(Map.Entry<Integer, Integer> e: map.entrySet()){
            sum += e.getValue();
            res = Math.max(res,sum);
        }

        return res;
    }
}