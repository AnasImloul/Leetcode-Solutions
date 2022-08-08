class Solution {
    public int numBusesToDestination(int[][] routes, int source, int target) {
        if(source == target) {
            return 0;
        }
        
        int n = routes.length;
        
        HashMap<Integer, HashSet<Integer>> setMap = new HashMap<>(); // stores stops on each bus route in hashet for quick looksups later on
        HashMap<Integer, List<Integer>> adjMap = new HashMap<>(); // building bi-directional graph with bus routes as nodes.
        
        // (n == bus routes, m == stops in each route)
        for(int i=0;i<n;i++) { // O(n*m) 
            HashSet<Integer> set = new HashSet<>();
            for(int j=0;j<routes[i].length;j++) {
                set.add(routes[i][j]);
            }
            setMap.put(i, set);
        }
        
        for(int i=0;i<n;i++) { // O(n*n*m)
            List<Integer> adjStops = new ArrayList<>();
            
            Iterator<Integer> iterator = setMap.get(i).iterator();
            
            while(iterator.hasNext()) {
                int stop = iterator.next();
                for(int j=0;j<n;j++) {
                    if(i==j) {
                        continue;
                    }
                    if(setMap.get(j).contains(stop)) {
                        adjStops.add(j);
                    }
                }
            }            
            adjMap.put(i, adjStops);
        }
        
        List<Integer> startPts = new ArrayList<>();
        
        for(Integer key : setMap.keySet()) { // O(n)
            HashSet<Integer> routeSet = setMap.get(key);
            if(routeSet.contains(source)) {
                startPts.add(key);
            }
        }
        
        // BFS
        int answer = Integer.MAX_VALUE;
        for(Integer startRouteNum : startPts) { // O(n^3)
            int currmin = 1;
            HashSet<Integer> visited = new HashSet<>();
            Queue<Pair<Integer,Integer>> q = new LinkedList<>();
            q.add(new Pair(startRouteNum, currmin));
            visited.add(startRouteNum);
            
            
            boolean found = false;
            while(!q.isEmpty()) { // O(V+E) == O(n + n^2) == O(n^2)
                Pair<Integer, Integer> pair = q.poll();
                currmin = pair.getValue();
                if(setMap.get(pair.getKey()).contains(target)) {
                    found = true;
                    break;
                }
                for(Integer neighbour : adjMap.getOrDefault(pair.getKey(), new ArrayList<>())) {
                    if(!visited.contains(neighbour)) {
                        q.add(new Pair(neighbour, currmin+1));
                        visited.add(neighbour);
                    }
                }
            }
            
            if (found) {
                answer = Math.min(answer, currmin);
            }
        }
        
        return answer == Integer.MAX_VALUE ? -1 : answer;
    }
}
