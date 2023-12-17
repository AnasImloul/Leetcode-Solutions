// Runtime: 191 ms (Top 41.18%) | Memory: 44.60 MB (Top 39.41%)

/*
Algorithm:
--------------------------------------------------------------
1. Have a TreeMap where the keys are the dates and values 
   to those keys are the number of active events occuring on
   that date. This will keep the dates sorted according to 
   the keys.
2. During booking for a new event [start, end), number of
   events occuring on the start date increases by one and 
   same for the end date decreases by one. Hence modify the 
   map accordingly.
3. Calculate a running sum `sum` which holds the count of
   events currently running at that time. 
4. If `sum` becomes more than or equal to 3, then remove that 
   event and return `False`
5. If this does not occur then return `True`.
--------------------------------------------------------------
*/

class MyCalendarTwo {
    Map<Integer, Integer> map;
    public MyCalendarTwo() {
        map = new TreeMap();
    }
    public boolean book(int start, int end) {
        map.put(start, map.getOrDefault(start, 0)+1);
        map.put(end, map.getOrDefault(end, 0)-1);
        int sum=0;
        for(int val : map.values()){
            sum += val;
            if(sum >= 3){
                map.put(start, map.get(start)-1);
                map.put(end, map.get(end)+1);
                if(map.get(start) == 0)
                    map.remove(start);
                return false;
            }
        }
        return true;
    }
}
