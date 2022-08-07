class Solution {
    public String frequencySort(String s) {
      HashMap<Character,Integer> hm1=new HashMap<>();
      TreeMap<Integer,ArrayList<Character>> hm2=new TreeMap<>(Collections.reverseOrder());
        for(int i=0;i<s.length();i++)
        {
            char c=s.charAt(i);
            if(hm1.containsKey(c))
            { 
                hm1.put(c,hm1.get(c) + 1);
            }
            else
            {
                hm1.put(c,1);
            }
        }
        for(char c : hm1.keySet())
        {
            if(hm2.containsKey(hm1.get(c)))
            {
                ArrayList<Character> temp=hm2.get(hm1.get(c));
                temp.add(c);
                hm2.put(hm1.get(c),temp);
            }
            else
            {
                ArrayList<Character> temp=new ArrayList<>();
                temp.add(c);
                hm2.put(hm1.get(c),temp);
            }
        }
        StringBuilder sb=new StringBuilder("");
        for(int x :hm2.keySet())
        {
            ArrayList<Character> temp=hm2.get(x);
            for(char c: temp)
            {
                for(int i=0;i<x;i++){
                sb.append(c);
                }
            }
        }
        return sb.toString();
    }
}
