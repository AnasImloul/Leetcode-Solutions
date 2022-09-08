// Runtime: 157 ms (Top 14.06%) | Memory: 126.7 MB (Top 62.50%)
class Solution {
    public List<List<String>> displayTable(List<List<String>> orders) {
        List<List<String>> ans = new ArrayList<>();
        List<String> head = new ArrayList<>();
        head.add("Table");
        Map<Integer, Map<String,Integer>> map = new TreeMap<>();
        for(List<String> s: orders){
            if(!head.contains(s.get(2))) head.add(s.get(2));
            int tbl = Integer.parseInt(s.get(1));
            map.putIfAbsent(tbl, new TreeMap<>());
            if(map.get(tbl).containsKey(s.get(2))){
                Map<String, Integer> m = map.get(tbl);
                m.put(s.get(2), m.getOrDefault(s.get(2), 0)+1);
            }else{
                map.get(tbl).put(s.get(2), 1);
            }
        }
        String[] arr = head.toArray(new String[0]);
        Arrays.sort(arr, 1, head.size());
        head = Arrays.asList(arr);
        ans.add(head);

        for(Map.Entry<Integer, Map<String, Integer>> entry: map.entrySet()){
            List<String> l = new ArrayList<>();
            l.add(entry.getKey() + "");
            Map<String,Integer> m = entry.getValue();
            for(int i=1; i<arr.length; i++){
                if(m.containsKey(arr[i])){
                    l.add(m.get(arr[i])+"");
                }else{
                    l.add("0");
                }
            }
            ans.add(l);
        }
        System.out.print(map);
        return ans;
    }
}