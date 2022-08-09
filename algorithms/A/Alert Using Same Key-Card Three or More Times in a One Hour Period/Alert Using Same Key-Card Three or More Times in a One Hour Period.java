class Solution {
    public List<String> alertNames(String[] keyName, String[] keyTime) {
        Map<String, PriorityQueue<Integer>> map = new HashMap<>();
		// for every entry in keyName and keyTime, add that time to a priorityqueue for that name
        for(int i=0;i<keyName.length;i++){
            PriorityQueue<Integer> pq = map.getOrDefault(keyName[i], new PriorityQueue<Integer>());
			//convert the time to an integer (0- 2359 inclusive) for easy comparisons
            pq.add(Integer.parseInt(keyTime[i].substring(0,2))*100+Integer.parseInt(keyTime[i].substring(3)));
            map.put(keyName[i],pq);
        }
        
		// Generate the "answer" list
        List<String> ans = new ArrayList<>();
        for(String s: map.keySet()){
			// For each name in the map, determine if that name used the keycard within 1 hour
            PriorityQueue<Integer> pq = map.get(s);
            if(active(pq)){
                ans.add(s);
            }
        }
        
		// Sort the names alphabetically
        Collections.sort(ans);
        return ans;
    }
    
	// Greedy function to determine if there were 3 uses within an hour
    private boolean active(PriorityQueue<Integer> pq){
		// If there are two or less entries, the user could not have entered 3 times, return false
        if(pq.size()<3) return false;
		
		// Create rolling data
		// Using PriorityQueues, the lowest number is removed first by default
        int a = pq.poll();
        int b = pq.poll();
        int c = pq.poll();
        
		// Test if two entrances are within 1 hour (100 in integer)
        if(c-a <=100) return true;
        while(pq.size()>0){
            a = b;
            b = c;
            c = pq.poll();
            if(c-a <=100) return true;
        }
		
		// If the full Queue has been checked, return false
        return false;
    }
}
