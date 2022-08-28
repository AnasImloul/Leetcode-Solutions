// Runtime: 16 ms (Top 40.82%) | Memory: 46.2 MB (Top 88.53%)
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String,ArrayList<String>> hm=new HashMap<>();
        for(String s : strs)
        {
            char ch[]=s.toCharArray();
            Arrays.sort(ch);
            StringBuilder sb=new StringBuilder("");
            for(char c: ch)
            {
                sb.append(c);
            }
            String str=sb.toString();
            if(hm.containsKey(str))
            {
              ArrayList<String> temp=hm.get(str);
              temp.add(s);
              hm.put(str,temp);
            }
            else
            {
                ArrayList<String> temp=new ArrayList<>();
                temp.add(s);
                hm.put(str,temp);
            }
        }
        System.out.println(hm);
        List<List<String>> res=new ArrayList<>();
        for(ArrayList<String> arr : hm.values())
        {
            res.add(arr);
        }
        return res;
    }
}