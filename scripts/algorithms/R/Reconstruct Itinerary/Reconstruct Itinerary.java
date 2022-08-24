// Runtime: 7 ms (Top 90.17%) | Memory: 50.3 MB (Top 42.47%)
class Solution {
    LinkedList<String> res = new LinkedList<>();

    public List<String> findItinerary(List<List<String>> tickets) {
        HashMap<String,PriorityQueue<String>> map= new HashMap<>();
        for(int i=0;i<tickets.size();i++){
            String a=tickets.get(i).get(0);
            String b=tickets.get(i).get(1);
            if(!map.containsKey(a)){
                PriorityQueue<String> temp = new PriorityQueue();
                map.put(a,temp);
            }
            map.get(a).add(b);
        }

        dfs("JFK",map);
        return res;

    }
    private void dfs(String departure,HashMap<String,PriorityQueue<String>> map){
        PriorityQueue<String> arrivals= map.get(departure);
        while(arrivals!=null &&!arrivals.isEmpty()){
            dfs(arrivals.poll(),map);
        }
        res.addFirst(departure);
    }
}