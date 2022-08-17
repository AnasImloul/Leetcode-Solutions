class Solution {
    public List<String> watchedVideosByFriends(List<List<String>> watchedVideos, int[][] friends, int id, int level) {
        int n = friends.length;
        boolean[] visited = new boolean[n];
        List<List<Integer>> graph = new ArrayList<>();
        for(int i=0;i<n;i++) graph.add(new ArrayList<>());
        for(int i=0;i<n;i++){
            for(int j=0;j<friends[i].length;j++){
                graph.get(i).add(friends[i][j]);
            }
        }
        // System.out.println(graph.get(0));
        Queue<Integer> queue = new ArrayDeque<>();
        queue.offer(id);
        visited[id] = true;
        Map<String,Integer> answer = new HashMap<>();
        while(!queue.isEmpty() && level>0){
            int size = queue.size();
            for(int i=0;i<size;i++){
                int vertex = queue.remove();
                for(int child: graph.get(vertex)){
                    if(!visited[child]){
                        //   if(level == 1) System.out.println(watchedVideos.get(child));
                        if(level == 1) {
                            for(String a: watchedVideos.get(child)){
                                answer.put(a,answer.getOrDefault(a,0)+1);
                            }
                        }
                        visited[child] = true;
                        queue.offer(child);
                    }
                }
            }
            level--;
        }
        Queue<String[]> sortedQueue = new PriorityQueue<>((a,b)->{
            if(a[1].equals(b[1])) return a[0].compareTo(b[0]);
            return Integer.parseInt(a[1])-Integer.parseInt(b[1]);
        });
        for(String key: answer.keySet()){
            sortedQueue.offer(new String[]{key,Integer.toString(answer.get(key))});
        }
        List<String> finalAnswer = new ArrayList<>();
        while(!sortedQueue.isEmpty()) finalAnswer.add(sortedQueue.remove()[0]);
        return finalAnswer;
    }
}
