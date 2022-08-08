class Solution {
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        Map<Integer, List<Integer>> employeesByManager = new HashMap<>();
        employeesByManager.put(headID, new ArrayList<>());
        for(int i = 0; i < manager.length; i++) {
            int managerId = manager[i];
            if(managerId != -1) {
                employeesByManager.computeIfAbsent(managerId, k -> new ArrayList<>()).add(i);
            }
        }
        int maxTime = -1;
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{headID, informTime[headID]});
        while(!q.isEmpty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int[] currentManagerAndTime = q.poll();
                maxTime = Math.max(maxTime, currentManagerAndTime[1]);
                List<Integer> reportees = employeesByManager.get(currentManagerAndTime[0]);
                if(reportees != null && !reportees.isEmpty()) {
                    for(int reportee : reportees) {
                        if(informTime[reportee] != 0) {
                            q.add(new int[]{reportee, informTime[reportee] + currentManagerAndTime[1]});
                        }
                    }
                }
            }
        }
        return maxTime;
    }
}
