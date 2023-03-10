class Solution {
    public String[] uncommonFromSentences(String s1, String s2) {
        List<String> list=new LinkedList<>();
        Map<String, Integer> map=new HashMap<>();
        String[] arr1=s1.split(" ");
        String[] arr2=s2.split(" ");
        for(int i=0;i<arr1.length;i++){
            map.put(arr1[i],map.getOrDefault(arr1[i],0)+1);
        }
        for(int i=0;i<arr2.length;i++){
            map.put(arr2[i],map.getOrDefault(arr2[i],0)+1);
        }
        for(Map.Entry<String, Integer> entry:map.entrySet()){
            if(entry.getValue()==1)
                list.add(entry.getKey());
        }
        String[] res=new String[list.size()];
        for(int i=0;i<res.length;i++){
            res[i]=list.get(i);
        }
        return res;
    }
}