class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String,Integer> map=new LinkedHashMap<>();
        for(String word:words) 
            map.put(word,map.getOrDefault(word,0)+1);
        PriorityQueue<Pair<String,Integer>> queue=new PriorityQueue<>(new Comparator<Pair<String,Integer>>(){
            @Override
            public int compare(Pair<String,Integer> a,Pair<String,Integer> b){
                if(a.getValue()!=b.getValue()) return b.getValue()-a.getValue();
                return a.getKey().compareTo(b.getKey());
            }
        });
        map.forEach((key,val)->{
            queue.add(new Pair(key,val));
        });
        List<String> list=new ArrayList<>();
        while(k>0){
            list.add(queue.poll().getKey());
            k--;
        }
        return list;
    }
}