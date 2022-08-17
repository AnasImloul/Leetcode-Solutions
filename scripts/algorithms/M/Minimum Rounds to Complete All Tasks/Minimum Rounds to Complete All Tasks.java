/**
	Each round, we can complete either 2 or 3 tasks of the same difficulty level
    Time: O(n)
    Space: O(n)
*/
class Solution {
    public int minimumRounds(int[] tasks) {
        int round = 0;
        Map<Integer, Integer> taskMap = new HashMap<>(); // map of <task,  number of each task>
        for (int i = 0; i < tasks.length; i++) {
            taskMap.put(tasks[i], taskMap.getOrDefault(tasks[i], 0) + 1);
        }
        
        for (Map.Entry<Integer, Integer> entry : taskMap.entrySet()) {
            if (entry.getValue() == 1) {
                return -1; // we cannot complete if there is only 1 task
            }
			// try to take as many 3's as possible
            round += entry.getValue() / 3; 
			
            /*
				We can have 1 or 2 tasks remaining. We're not supposed to take task of count 1, but we can 'borrow' 1 from the previous
				ex. [5,5,5,5,5,5,5] -> [5,5,5][5,5,5][5]
				In this example, treat the last [5,5,5], [5] as [5,5], [5,5]
            */
            if (entry.getValue() % 3 != 0) { 
                round++; 
            }
        }
        return round;
    }
}