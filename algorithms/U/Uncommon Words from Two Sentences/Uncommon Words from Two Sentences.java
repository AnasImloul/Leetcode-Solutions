class Solution {
    public String[] uncommonFromSentences(String s1, String s2) {
       HashMap<String,Integer> hmap=new HashMap<>();
       for(String s:s1.split(" "))
            hmap.put(s,hmap.getOrDefault(s,0)+1);
        for(String s:s2.split(" "))
            hmap.put(s,hmap.getOrDefault(s,0)+1);
        StringBuilder sb = new StringBuilder();
        for(String s:hmap.keySet())
        {
            if(hmap.get(s)==1)
                sb.append(s+" ");
        }
        
        if(sb.toString().equals(""))
            return new String[0];
        
        return sb.toString().trim().split(" ");
    }
}
