// Runtime: 44 ms (Top 25.64%) | Memory: 42.9 MB (Top 94.32%)
class Solution {
    public boolean canConstruct(String s, int k) {
        if(k==s.length())
        {
            return true;
        }
        else if(k>s.length())
        {
            return false;
        }
        Map<Character,Integer> map=new HashMap<Character,Integer>();
        for(int i=0;i<s.length();i++)
        {
            if(map.containsKey(s.charAt(i)))
            {
                int count=map.get(s.charAt(i));
                map.put(s.charAt(i),count+1);
            }
            else
            {
                map.put(s.charAt(i),1);
            }
        }
        int odd=0;
        for(Map.Entry<Character,Integer>ele:map.entrySet())
        {
            if((ele.getValue()%2)==1)
            {
                odd++;
            }
        }
        return (odd<=k);
    }
}